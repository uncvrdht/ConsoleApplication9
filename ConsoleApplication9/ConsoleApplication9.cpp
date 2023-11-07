#include <iostream>
using namespace std;
class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int denom) : numerator(num), denominator(denom) {
    }

    Fraction operator+(int value) const {
        return Fraction(numerator + value * denominator, denominator);
    }

    Fraction operator+(double value) const {
        return Fraction(numerator + static_cast<int>(value * denominator), denominator);
    }
};

Fraction operator+(int value, const Fraction& fraction) {
    return fraction + value;
}

Fraction operator+(double value, const Fraction& fraction) {
    return fraction + value;
}

class Student {
public:
    double averageGrade;

    Student(double avg) : averageGrade(avg) {
    }

    bool operator==(const Student& other) const {
        return averageGrade == other.averageGrade;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    bool operator>(const Student& other) const {
        return averageGrade > other.averageGrade;
    }

    bool operator<(const Student& other) const {
        return averageGrade < other.averageGrade;
    }
};

class Group {
public:
    int numberOfStudents;

    Group(int count) : numberOfStudents(count) {
    }

    bool operator==(const Group& other) const {
        return numberOfStudents == other.numberOfStudents;
    }

    bool operator!=(const Group& other) const {
        return !(*this == other);
    }
};

int main() {
    Fraction fraction1(1, 2);
    Fraction fraction2(1, 3);

    Fraction result = fraction1 + 3;
    cout << "Fraction + int: " << result.numerator << "/" << result.denominator << endl;

    result = 5 + fraction2;
    cout << "int + Fraction: " << result.numerator << "/" << result.denominator << endl;

    result = fraction1 + 0.25;
    cout << "Fraction + double: " << result.numerator << "/" << result.denominator << endl;

    result = 1.5 + fraction2;
    cout << "double + Fraction: " << result.numerator << "/" << result.denominator << endl;

    Student student1(85.5);
    Student student2(90.0);

    if (student1 == student2) {
        cout << "Students are equal." << endl;
    }
    else {
        cout << "Students are not equal." << endl;
    }

    if (student1 != student2) {
        cout << "Students are not equal." << endl;
    }
    else {
        cout << "Students are equal." << endl;
    }

    if (student1 > student2) {
        cout << "Student 1 has a higher grade." << endl;
    }
    else if (student1 < student2) {
        cout << "Student 2 has a higher grade." << endl;
    }
    else {
        cout << "Students have the same grade." << endl;
    }

    Group group1(30);
    Group group2(25);

    if (group1 == group2) {
        cout << "Groups have the same number of students." << endl;
    }
    else {
        cout << "Groups have different numbers of students." << endl;
    }

    if (group1 != group2) {
        cout << "Groups have different numbers of students." << endl;
    }
    else {
        cout << "Groups have the same number of students." << endl;
    }

    return 0;
}
/*

Добавить четыре функции, которые позволят сложить дробь и
целое/вещественное число (все возвращают в результате Fraction):
Fraction + int
int + Fraction
Fraction + double
double + Fraction
ГОТОВО


Добавить четыре функции для сравнения двух студентов 
(по среднему баллу за домашние задания) 
возвращают в результате bool:
Student == Student
Student != Student
Student > Student
Student < Student
ГОТОВО 

Добавить две функции для сравнения двух групп (по количеству студентов в группе) возвращают в результате bool:
Group == Group
Group != Group
ГОТОВО 

Добавлены перегрузки операторов для Fraction.

Добавлены перегрузки операторов для Student 

Добавлены перегрузки операторов для Group.

*/