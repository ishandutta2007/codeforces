#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, x, y;

int main() {
    std::cin >> n; x = 0; y = 1;
    while (true) {
        if (x > n && y > n) { break; }
        if (x == n || y == n) { std::cout << 1; return 0; }
        if (y & 1) {
            x = y * 2 - 1; y = y * 2;
        } else {
            x = y * 2; y = y * 2 + 1;
        }
    }
    std::cout << 0;
    return 0;
}