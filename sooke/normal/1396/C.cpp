#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, x, y, z, d, a[N];
long long ans, w[N][2], f[N];

int main() {
    n = read(); x = read(); y = read(); z = read(); d = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        w[i][0] = 1ll * x * a[i] + z;
        w[i][1] = std::min(1ll * x * (a[i] + 2), 0ll + x + y);
        w[i][1] = std::min(w[i][1], w[i][0]);
    }
    memset(f, 60, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + w[i][0] + d;
        if (i > 1) {
            f[i] = std::min(f[i], f[i - 2] + w[i - 1][1] + w[i][1] + d * 4ll);
        }
        if (i > 2) {
            f[i] = std::min(f[i], f[i - 3] + w[i - 2][1] + w[i - 1][1] + w[i][1] + d * 7ll);
        }
    }
    ans = std::min(f[n] - d, f[n - 2] + w[n - 1][1] + w[n][0] + d * 2ll);
    if (n > 2) {
        ans = std::min(ans, f[n - 3] + w[n - 2][1] + w[n - 1][1] + w[n][0] + d * 5ll);
    }
    printf("%lld\n", ans);
    return 0;
}