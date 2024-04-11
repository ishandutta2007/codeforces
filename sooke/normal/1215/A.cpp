#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int a, b, x, y, n, l = 1e9, r = -1e9;

int main() {
    a = read(); b = read(); x = read(); y = read(); n = read();
    for (int i = 0; i <= n; i++) {
        r = std::max(r, std::min(a, i / x) + std::min(b, (n - i) / y));
    } l = std::max(0, n - (x - 1) * a - (y - 1) * b);
    printf("%d %d\n", l, r);
    return 0;
}