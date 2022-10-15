#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, x, y, a[N], b[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        for (int i = 0; i < n; i++) {
            b[i] = std::abs(a[i]);
            if (i & 1) { b[i] = -b[i]; }
            printf("%d ", b[i]);
        }
        printf("\n");
    }
    return 0;
}