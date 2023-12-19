#include <iostream>
#include <vector>

// Base Animal class
class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {}
};

// Derived Cat class
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!\n";
    }
};

// Derived Dog class
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!\n";
    }
};

// Function to make animals in the list make sounds
void makeSounds(const std::vector<Animal*>& animals) {
    for (const auto& animal : animals) {
        animal->makeSound();
    }
}

int main() {
    // Create instances of Cat, Dog, and add them to the list
    std::vector<Animal*> animalsChasingList;
    Cat cat1, cat2;
    Dog dog1, dog2;

    animalsChasingList.push_back(&cat1);
    animalsChasingList.push_back(&cat2);
    animalsChasingList.push_back(&dog1);
    animalsChasingList.push_back(&dog2);

    // Make sounds of animals in the list
    makeSounds(animalsChasingList);

    // Cleanup dynamic objects
    for (const auto& animal : animalsChasingList) {
        delete animal;
    }

    return 0;
}
