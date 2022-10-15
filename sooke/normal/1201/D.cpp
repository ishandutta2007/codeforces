#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, k, q, l[N], r[N], a[N];
long long ans, f[2][N];

signed main() {
    n = read(); m = read(); k = read(); q = read();
    for (int i = 0; i < n; i++) {
        l[i] = 1e9; r[i] = -1e9;
    }
    for (int i = 0; i < k; i++) {
        int x = read() - 1, y = read() - 1;
        l[x] = std::min(l[x], y);
        r[x] = std::max(r[x], y);
    }
    for (int i = 0; i < q; i++) { a[i] = read() - 1; }
    std::sort(a, a + q);
    if (l[0] <= r[0]) {
        f[0][0] = r[0] + r[0] - l[0]; f[1][0] = r[0];
        ans = std::min(f[0][0], f[1][0]);
    } else {
        l[0] = r[0] = f[0][0] = f[1][0] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (l[i] <= r[i]) {
            f[0][i] = f[1][i] = 1e18;
            for (int x = 0; x <= 1; x++) {
                for (int y = 0; y <= 1; y++) {
                    int s, t, j;
                    if (x == 0) { s = l[i]; } else { s = r[i]; }
                    if (y == 0) { t = l[i - 1]; } else { t = r[i - 1]; }
                    j = std::lower_bound(a, a + q, std::max(s, t)) - a;
                    if (j >= 0 && j < q) {
                        f[x][i] = std::min(f[x][i], f[y][i - 1] + (a[j] - s) + (a[j] - t));
                    }
                    j = std::upper_bound(a, a + q, std::min(s, t)) - a - 1;
                    if (j >= 0 && j < q) {
                        f[x][i] = std::min(f[x][i], f[y][i - 1] + (s - a[j]) + (t - a[j]));
                    }
                    j = std::lower_bound(a, a + q, s) - a;
                    if (j >= 0 && j < q && a[j] <= t) {
                        f[x][i] = std::min(f[x][i], f[y][i - 1] + t - s);
                    }
                    j = std::lower_bound(a, a + q, t) - a;
                    if (j >= 0 && j < q && a[j] <= s) {
                        f[x][i] = std::min(f[x][i], f[y][i - 1] + s - t);
                    }
                }
            }
            f[0][i] += r[i] - l[i] + 1;
            f[1][i] += r[i] - l[i] + 1;
            std::swap(f[0][i], f[1][i]);
            ans = std::min(f[0][i], f[1][i]);
        } else {
            l[i] = l[i - 1];
            r[i] = r[i - 1];
            f[0][i] = f[0][i - 1] + 1;
            f[1][i] = f[1][i - 1] + 1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}