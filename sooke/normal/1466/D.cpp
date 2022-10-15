#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], deg[N];
long long f[N];
std::vector<int> e[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        long long ans = 0;
        std::priority_queue<std::pair<int, int>> que;
        for (int u = 1; u <= n; u++) {
            a[u] = read(); e[u].clear(); ans += a[u];
        }
        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            e[u].push_back(v); e[v].push_back(u);
        }
        for (int u = 1; u <= n; u++) {
            deg[u] = e[u].size();
            if (deg[u] == 1) { continue; }
            que.push({a[u], deg[u] - 1});
        }
        for (int i = 1; i < n; i++) {
            printf("%lld ", ans);
            if (i == n - 1) { break; }
            int x, y;
            ans += x = que.top().first;
            y = que.top().second;
            que.pop();
            if (y == 1) { continue; }
            que.push({x, y - 1});
        }
        printf("\n");
    }
    return 0;
}