#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 205;

int n, r1, c1, r2, c2, r3, c3, r, c;

bool solve() {
    bool x = std::abs(r1 - r2) + std::abs(c1 - c2) == 1;
    bool y = std::abs(r1 - r3) + std::abs(c1 - c3) == 1;
    bool z = std::abs(r2 - r3) + std::abs(c2 - c3) == 1;
    if (x && y) {
        if ((r1 == 1 || r1 == n) && (c1 == 1 || c1 == n)) { return r1 == r || c1 == c; }
        return r1 % 2 == r % 2 || c1 % 2 == c % 2;
    }
    if (x && z) {
        if ((r2 == 1 || r2 == n) && (c2 == 1 || c2 == n)) { return r2 == r || c2 == c; }
        return r2 % 2 == r % 2 || c2 % 2 == c % 2;
    }
    if (y && z) {
        if ((r3 == 1 || r3 == n) && (c3 == 1 || c3 == n)) { return r3 == r || c3 == c; }
        return r3 % 2 == r % 2 || c3 % 2 == c % 2;
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); r1 = read(); c1 = read(); r2 = read(); c2 = read(); r3 = read(); c3 = read(); r = read(); c = read();
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}