#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}

const int N = 1e3 + 5;

int n, m, ans, ord[N], a[N], deg[N];
std::vector<int> e[N];
std::vector<std::pair<int, int>> p[N], q;

int main() {
    int T = read();
    for (; T; T--) {
        n = read(); m = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read(); p[i].clear();
            if (a[i] > 0) { p[i].push_back({1, a[i] >= mod ? -(a[i] % mod) : a[i]}); }
            e[i].clear();
        }
        for (; m; m--) {
            int u = read(), v = read();
            e[u].push_back(v); deg[v]++;
        }
        std::queue<int> que;
        for (int u = 1; u <= n; u++) {
            if (deg[u] == 0) { que.push(u); }
        }
        for (int i = 0; !que.empty(); que.pop()) {
            int u = que.front();
            ord[++i] = u;
            for (auto v : e[u]) {
                deg[v]--;
                if (deg[v] == 0) { que.push(v); }
            }
        }
        for (int i = 1; i <= n; i++) {
            int u = ord[i];
            std::sort(p[u].begin(), p[u].end());
            q.clear();
            int l = -1, r = 1;
            for (auto j : p[u]) {
                // printf("for %d: %d %d\n", u, j.first, j.second);
                if (r <= 0) {
                    if (j.second <= 0) {
                        r = -add(-j.second, -r);
                    } else {
                        r = -add(j.second - j.first + 1, -r);
                    }
                } else {
                    if (l == -1) {
                        l = j.first; r = j.second;
                    } else if (j.first > r + 1) {
                        q.push_back({l, r});
                        l = j.first; r = j.second;
                    } else if (j.second <= 0) {
                        r = -add(-j.second, r - l + 1);
                    } else {
                        r += j.second - j.first + 1;
                    }
                    if (r >= mod) { r = -((r - l + 1) % mod); }
                }
            }
            if (l != -1) { q.push_back({l, r}); }
            p[u] = q;
            for (auto v : e[u]) {
                for (auto j : p[u]) {
                    if (j.second <= 0) {
                        p[v].push_back({j.first + 1, j.second});
                    } else {
                        p[v].push_back({j.first + 1, j.second + 1});
                    }
                }
            }
        }
        if (p[ord[n]].empty()) { ans = 0; } else {
            ans = p[ord[n]].back().second <= 0 ? sub(add(p[ord[n]].back().first % mod, -p[ord[n]].back().second), 1) : p[ord[n]].back().second % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}