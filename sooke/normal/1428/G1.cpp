#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const long long inf = 1e18;
const int N = 3e6 + 5;

int n, k, q, pwr[9], w[N];
long long f[N], g[N], p[N];

void solve(int k, long long f[]) {
    for (int x = 1; x <= n; x++) {
        f[x] = -inf;
    }
    for (int i = 0; i < 6; i++) {
        long long y, s = 0;
        for (y = 1; s + y < k; y *= 2) {
            long long u = y * w[i];
            long long v = y * pwr[i];
            for (int x = n; x >= v; x--) {
                f[x] = std::max(f[x], f[x - v] + u);
            }
            s += y;
        }
        long long u = (k - s) * w[i];
        long long v = (k - s) * pwr[i];
        for (int x = n; x >= v; x--) {
            f[x] = std::max(f[x], f[x - v] + u);
        }
    }
}

int main() {
    k = read();
    pwr[0] = 3;
    pwr[1] = 30;
    pwr[2] = 300;
    pwr[3] = 3000;
    pwr[4] = 30000;
    pwr[5] = 300000;
    n = 999999;
    for (int i = 0; i < 6; i++) {
        w[i] = read();
    }
    solve(k * 3, f);
    solve((k - 1) * 3, g);
    long long maxans = -inf;
    for (int x = 1; x <= n; x++) {
        maxans = std::max(maxans, g[x]);
        f[x] = std::max(f[x], maxans);
        f[x] = std::max(f[x], 0ll);
    }
    q = read();
    for (int y = 0; y <= n; y++) {
        int x = y;
        for (int i = 0; i < 6; i++) {
            if (x % 10 == 3) { p[y] += w[i]; }
            if (x % 10 == 6) { p[y] += w[i] * 2ll; }
            if (x % 10 == 9) { p[y] += w[i] * 3ll; }
            x /= 10;
        }
    }
    for (int i = 0; i < q; i++) {
        int x = read();
        if (k == 1) {
            printf("%lld\n", p[x]);
            continue;
        }
        long long ans = p[x];
        ans = std::max(ans, f[x]);
        for (int y = 0; y < x; y++) {
            ans = std::max(ans, g[y] + p[x - y]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}