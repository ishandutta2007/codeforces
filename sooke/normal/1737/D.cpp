#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 505;

int n, m, dis[N][N];
std::vector<std::pair<int, int>> e[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int u = 1; u <= n; u++) {
            e[u].clear();
        }
        for (int i = 0; i < m; i++) {
            int u = read(), v = read(), w = read();
            e[u].push_back({v, w}); e[v].push_back({u, w});
        }
        for (int u = 1; u <= n; u++) {
            std::queue<int> que;
            for (int v = 1; v <= n; v++) { dis[u][v] = 1e9; }
            dis[u][u] = 0; que.push(u);
            for (; !que.empty(); que.pop()) {
                int v = que.front();
                for (auto i : e[v]) {
                    int w = i.first;
                    if (dis[u][w] > dis[u][v] + 1) {
                        dis[u][w] = dis[u][v] + 1; que.push(w);
                    }
                }
            }
        }
        long long ans = 9e18;
        for (int u = 1; u <= n; u++) {
            for (auto i : e[u]) {
                int v = i.first, w = i.second, c = 1e9;
                c = std::min(c, dis[1][u] + dis[n][v]);
                c = std::min(c, dis[1][v] + dis[n][u]);
                if (v > u) { continue; }
                for (int j = 1; j <= n; j++) {
                    c = std::min(c, dis[j][u] + 1 + dis[1][j] + dis[n][j]);
                    c = std::min(c, dis[j][v] + 1 + dis[1][j] + dis[n][j]);
                }
                ans = std::min(ans, 1ll * (c + 1) * w);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}