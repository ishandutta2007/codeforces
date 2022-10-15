#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, max, min, a[N];

bool solve() {
    for (int i = 1; i < n; i++) {
        if (std::abs(a[i] - a[i - 1]) > 1) {
            printf("YES\n%d %d\n", i, i + 1);
            return true;
        }
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = read(); }
        if (solve()); else {
            printf("NO\n");
        }
    }
    return 0;
}