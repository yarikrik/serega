#include <iostream>
#include <string>

using namespace std;

class GameCharacter {
protected:
    string name;
    int health;

public:
    GameCharacter(const string& name, int health)
        : name(name), health(health) {}

    void showInfo() const {
        cout << "Personazh: " << name << ", zdorove: " << health << endl;
    }

    virtual void attack() const {
        cout << name << " vypolnyaet obychnuyu ataku." << endl;
    }

    virtual ~GameCharacter() = default;
};

class Warrior : public GameCharacter {
private:
    int swordDamage;

public:
    Warrior(const string& name, int health, int swordDamage)
        : GameCharacter(name, health), swordDamage(swordDamage) {}

    void attack() const override {
        cout << name << " (Voin) atakuet mechom i nanosit "
             << swordDamage << " urona!" << endl;
    }
};

class Mage : public GameCharacter {
private:
    int mana;

public:
    Mage(const string& name, int health, int mana)
        : GameCharacter(name, health), mana(mana) {}

    void attack() const override {
        cout << name << " (Mag) ispolzuet zaklinanie, tratit "
             << mana / 10 << " many iz " << mana << "!" << endl;
    }
};

class Archer : public GameCharacter {
private:
    int arrows;

public:
    Archer(const string& name, int health, int arrows)
        : GameCharacter(name, health), arrows(arrows) {}

    void attack() const override {
        cout << name << " (Luchnik) strelyaet iz luka. Ostalos strel: "
             << arrows << "!" << endl;
    }
};

int main() {
    Warrior warrior("Artur", 150, 40);
    Mage mage("Merlin", 90, 200);
    Archer archer("Robin", 110, 30);

    GameCharacter* ptr = nullptr;

    cout << "=== Cherez ukazatel ===" << endl;

    ptr = &warrior;
    ptr->showInfo();
    ptr->attack();
    cout << endl;

    ptr = &mage;
    ptr->showInfo();
    ptr->attack();
    cout << endl;

    ptr = &archer;
    ptr->showInfo();
    ptr->attack();
    cout << endl;

    cout << "=== Cherez ssylku ===" << endl;
    GameCharacter& ref = mage;
    ref.attack();

    return 0;
}