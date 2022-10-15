#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, f[N], g[N];
long long ans;

int main() {
    for (int T = read(); T; T--) {
        n = read(); ans = 0;
        std::vector<int> a[2];
        for (int i = 1; i <= n; i++) { f[i] = read(); }
        for (int i = 1; i <= n; i++) {
            int u = f[i], x = read();
            a[u].push_back(x);
        }
        for (auto x : a[0]) { ans += x; }
        for (auto x : a[1]) { ans += x; }
        std::sort(a[0].begin(), a[0].end());
        std::sort(a[1].begin(), a[1].end());
        if (a[0].size() < a[1].size()) { std::swap(a[0], a[1]); }
        if (a[0].size() == a[1].size()) {
            for (auto x : a[0]) { ans += x; }
            for (auto x : a[1]) { ans += x; }
            ans -= std::min(a[0][0], a[1][0]);
        } else {    
            std::reverse(a[0].begin(), a[0].end());
            std::reverse(a[1].begin(), a[1].end());
            for (auto x : a[1]) { ans += x; }
            for (int i = 0; i < a[1].size(); i++) {
                ans += a[0][i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}