#include <iostream>

int n;

int main() {
    std::cin >> n;
    std::cout << (n << 1 | 1) / 3;
    return 0;
}