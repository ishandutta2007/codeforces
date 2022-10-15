#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int m, n, ans, t[N], r[N], c[N], f[N];

int main() {
    m = read(); n = read();
    r[0] = c[0] = 1;
    for (int i = 1; i <= n; i++) {
        t[i] = read(); r[i] = read(); c[i] = read();
        f[i] = -1e9;
        for (int j = i - 1; j >= 0 && j >= i - 2000; j--) {
            if (std::abs(r[i] - r[j]) + std::abs(c[i] - c[j]) <= t[i] - t[j]) {
                f[i] = std::max(f[i], f[j] + 1);
            }
        }
        ans = std::max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}