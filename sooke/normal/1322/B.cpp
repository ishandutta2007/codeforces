#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, ans, f[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) { f[i] = read(); }
    for (int u = 25, x; u >= 0; u--) {
        x = 1 << u;
        std::sort(f, f + n);
        for (int i = 0; i < n; i++) {
            int a = std::lower_bound(f, f + i, x * 1 - f[i]) - f;
            int b = std::lower_bound(f, f + i, x * 2 - f[i]) - f;
            int c = std::lower_bound(f, f + i, x * 3 - f[i]) - f;
            if ((b - a - c + i) % 2 != 0) { ans ^= x; }
        }
        for (int i = 0; i < n; i++) {
            if (f[i] & x) { f[i] ^= x; }
        }
    }
    printf("%d\n", ans);
    return 0;
}