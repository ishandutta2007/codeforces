#include <iostream>

long long n;

int main() {
    std::cin >> n;
    std::cout << (!n ? 0 : n & 1 ? n + 1 >> 1 : n + 1);
    return 0;
}