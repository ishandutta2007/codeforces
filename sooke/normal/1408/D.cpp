#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e3 + 5, M = 1e6 + 5;

int n, m, ans, now, a[N], b[N], c[N], d[N], f[M];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); b[i] = read(); }
    for (int i = 1; i <= m; i++) { c[i] = read(); d[i] = read(); }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                f[c[j] - a[i]] = std::max(f[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }
    ans = 1e9;
    for (int i = M - 1; i >= 0; i--) {
        now = std::max(now, f[i]);
        ans = std::min(ans, now + i);
    }
    printf("%d\n", ans);
}