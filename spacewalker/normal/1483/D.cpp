#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 610;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll graph[NMAX][NMAX], check[NMAX][NMAX];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<tuple<int, int, int>> elist;
    memset(graph, 0x3f, sizeof graph);
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        if (u > v) swap(u, v);
        elist.emplace_back(u, v, w);
        graph[u][v] = graph[v][u] = w;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int q; scanf("%d", &q);
    memset(check, -1, sizeof check);
    for (int i = 0; i < q; ++i) {
        int u, v, l; scanf("%d %d %d", &u, &v, &l); --u; --v;
        check[u][v] = check[v][u] = l;
    }
    for (int k = 0; k < n; ++k) {
//        printf("iterating on %d\n", k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                check[i][k] = max(check[i][k], check[i][j] - graph[k][j]);
                check[k][j] = max(check[k][j], check[i][j] - graph[i][k]);
//                printf("checking %d %d path(%lld %lld): %d %d = %lld\n", i, j, check[i][j], graph[k][j], i, k, check[i][k]);
            }
        }
    }
    int ans = 0;
    for (auto [u, v, w] : elist) if (check[u][v] >= w) ++ans; //else printf("%d %d %d not useful\n", w, u, v);
    printf("%d\n", ans);
}