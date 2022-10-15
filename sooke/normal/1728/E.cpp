#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

void exgcd(long long a, long long b, long long &x, long long &y, long long &gcd) {
    if (b == 0) { gcd = a; x = 1; y = 0; return; }
    exgcd(b, a % b, y, x, gcd); y -= x * (a / b);
}

const int N = 3e5 + 5;

int n, q, a[N], b[N];
long long f[N];
std::vector<std::pair<int, int>> e;
std::vector<long long> dp[N];

long long query(long long m, long long x) {
    long long res = 0;
    if (n / m <= 300) {
        if (x > n) { return -1; }
        for (; x <= n; x += m) {
            res = std::max(res, f[x]);
        }
    } else {
        res = dp[m][x];
    }
    return res;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read(); f[0] += b[i];
        e.push_back({a[i] - b[i], i});
    }
    std::sort(e.begin(), e.end());
    std::reverse(e.begin(), e.end());
    for (int i = 0; i < n; i++) {
        f[i + 1] = f[i] + e[i].first;
    }
    for (int m = 1; n / m > 300; m++) {
        dp[m].resize(m);
        for (int x = 0; x < m; x++) {
            for (int i = x; i <= n; i += m) {
                dp[m][x] = std::max(dp[m][x], f[i]);
            }
        }
    }
    q = read();
    for (; q; q--) {
        int c = read(), d = read();
        long long x, y, g, h;
        exgcd(c, d, x, y, g);
        if (n % g != 0) { printf("-1\n"); continue; }
        x *= n / g * c; y *= n / g * d;
        h = c / g * d;
        printf("%lld\n", query(h, (x % h + h) % h));
    }
    return 0;
}