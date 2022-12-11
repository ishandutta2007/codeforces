#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 410;
constexpr int INF = 0x3f3f3f3f;

int dists[NMAX][NMAX];
int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<int, int>> elist;
    vector<vector<int>> graph(n);
    memset(dists, 0x3f, sizeof dists);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        --u; --v;
        elist.emplace_back(u, v);
        dists[u][v] = dists[v][u] = 1;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i) dists[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
    auto getAns = [&] (int i, int j) {
//        printf("getAns %d %d\n", i, j);
        vector<int> subGraphIn(n);
        for (auto [u, v] : elist) {
            if (dists[i][u] + 1 + dists[v][j] == dists[i][j]) {
//                printf("%d %d in subgraph\n", u, v);
                ++subGraphIn[v];
            }
            if (dists[i][v] + 1 + dists[u][j] == dists[i][j]) {
//                printf("%d %d in subgraph\n", v, u);
                ++subGraphIn[u];
            }
        }
        for (int k = 0; k < n; ++k) if (subGraphIn[k] > 1) return 0LL;
        vector<int> ijPath{j};
        while (ijPath.back() != i) {
            for (int k : graph[ijPath.back()]) if (dists[i][k] + 1 == dists[i][ijPath.back()]) ijPath.push_back(k);
        }
        vector<int> dist(n, -1);
        queue<int> q;
        for (int v : ijPath) {
            dist[v] = 0; q.push(v);
        }
        ll ans = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ll cterm = 0; 
            for (int nxt : graph[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                } else {
                    if (dists[i][nxt] + 1 == dists[i][cur] && dists[j][nxt] + 1 == dists[j][cur]) ++cterm; 
                }
            }
            if (dist[cur] > 0) ans = ans * cterm % MOD;
        }
        return ans;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lld ", getAns(i, j));
        }
        printf("\n");
    }
    return 0;
}