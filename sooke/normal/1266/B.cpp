#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

long long n;

bool check() {
    for (int i = 15; i <= 20; i++) {
        long long m = n - i;
        if (m >= 0 && m % 14 == 0) { return true; }
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}