#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int T, n, m, k;
long long a[N], sum[N];
std::vector<int> e[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int v = 1; v <= n; v++) {
            a[v] = read(); e[v].clear();
        }
        for (int i = 0; i < m; i++) {
            int u = read(), v = read();
            e[v].push_back(u);
        }
        k = 0;
        std::map<std::pair<int, int>, int> map;
        for (int v = 1; v <= n; v++) {
            int x = 0, y = 0;
            if (e[v].empty()) { continue; }
            std::sort(e[v].begin(), e[v].end());
            for (auto u : e[v]) {
                x = (1ll * x * 98765431 + u) % 998244353;
                y = ((1ll * y * 19260817) ^ u) % 998244853;
            }
            if (map[{x, y}] == 0) {
                map[{x, y}] = ++k; sum[k] = 0;
            }
            sum[map[{x, y}]] += a[v];
        }
        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = std::__gcd(ans, sum[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}