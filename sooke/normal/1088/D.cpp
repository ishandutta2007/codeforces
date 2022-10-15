#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

int a, b, x, y, lst;

int main() {
    std::cout << "? " << 0 << " " << 0 << std::endl; std::cin >> lst;
    for (int i = 29; ~i; i--) {
        if (lst != 0) {
            std::cout << "? " << (1 << i | a) << " " << (1 << i | b) << std::endl; std::cin >> x;
            if (lst == x || x == 0) {
                std::cout << "? " << a << " " << (1 << i | b) << std::endl; std::cin >> y;
                if (y == 1) { a |= 1 << i; b |= 1 << i; } lst = x;
            } else {
                if (x == 1) { b |= 1 << i; } else { a |= 1 << i; }
                std::cout << "? " << a << " " << b << std::endl; std::cin >> lst;
            }
        } else {
            std::cout << "? " << a << " " << b << std::endl; std::cin >> x;
            if (x == 0) {
                std::cout << "? " << a << " " << (1 << i | b) << std::endl; std::cin >> y;
                if (y == 1) { a |= 1 << i; b |= 1 << i; }
            } else if (x == 1) { a |= 1 << i; } else { b |= 1 << i; }
        }
    }
    std::cout << "! " << a << " " << b << std::endl;
    return 0;
}