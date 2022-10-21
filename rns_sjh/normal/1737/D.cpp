#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 300500;
const int M = 550;
const int inf = 1e9 + 50;
const int mod = 998244353;

int U[N], V[N], W[N], dist[M][M], que[M], vis[M];
vector<int> adj[M];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            U[i] = u, V[i] = v, W[i] = w;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans = 1e18;
        for (int i = 1; i <= n; i++) {
            int tot = 0;
            fill(vis, vis + n + 5, 0);
            que[tot++] = i;
            dist[i][i] = 0;
            vis[i] = 1;
            for (int j = 0; j < tot; j++) {
                int u = que[j];
                for (auto v : adj[u]) if (!vis[v]) {
                    dist[i][v] = dist[i][u] + 1;
                    que[tot++] = v;
                    vis[v] = 1;
                }
            }
            for (int j = 1; j <= m; j++) {
                int u = U[j], v = V[j], w = W[j];
                ll t = 1ll * (min(dist[i][u], dist[i][v]) + dist[i][1] + dist[i][n] + 2) * w;
                ans = min(ans, t);
            }
        }
        for (int i = 1; i <= m; i++) {
            int u = U[i], v = V[i], w = W[i];
            ll t = 1ll * (min(dist[1][u] + dist[n][v], dist[1][v] + dist[n][u]) + 1) * w;
            ans = min(ans, t);
        }
        printf("%lld\n", ans);
    }

    return 0;
}