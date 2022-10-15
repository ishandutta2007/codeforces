#include <iostream>

int main() {
    int n; std::cin >> n;
    if (n & 1) { std::cout << "contest"; } else { std::cout << "home"; }
    return 0;
}