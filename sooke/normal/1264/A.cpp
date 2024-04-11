#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, x, y, z, a[N], b[N], c[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = b[i] = -read(); }
        std::sort(b, b + n); m = std::unique(b, b + n) - b;
        for (int i = 0; i < n; i++) {
            int u = std::lower_bound(b, b + m, a[i]) - b;
            c[u]++;
        }
        x = c[0]; y = 0; z = 0; c[m] = 1e9;
        for (int i = 1; i <= m; i++) {
            if (y <= x) {
                y += c[i];
            } else {
                z += c[i];
                if (x + y + z > n / 2) {
                    z -= c[i];
                    break;
                }
            }
        }
        if  (x + y + z <= n / 2 && x < y && x < z) {
            printf("%d %d %d\n", x, y, z);
        } else {
            printf("0 0 0\n");
        }
        for (int i = 0; i <= m; i++) { c[i] = 0; }
    }
    return 0;
}