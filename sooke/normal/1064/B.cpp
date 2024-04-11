#include <iostream>

int main() {
    int n; std::cin >> n;
    while (std::cin >> n) { std::cout << (1 << __builtin_popcount(n)) << std::endl; }
    return 0;   
}