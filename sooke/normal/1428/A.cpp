#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int sx, sy, tx, ty;

int solve() {
    if (sx == tx || sy == ty) {
        return std::abs(sx - tx) + std::abs(sy - ty);
    }
    return std::abs(sx - tx) + std::abs(sy - ty) + 2;
}

int main() {
    for (int T = read(); T; T--) {
        sx = read(); sy = read(); tx = read(); ty = read();
        printf("%d\n", solve());
    }
    return 0;
}