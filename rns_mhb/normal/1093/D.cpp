#include <bits/stdc++.h>
using namespace std;

#define N 300020

const int mod = 998244353;

int t, n, m, pw[N], vis[N];
vector <int> adj[N];

bool dfs(int u, int &x, int &y, int b = 0) {
    vis[u] = b;
    if (b) y ++;
    else x ++;
    for (auto v : adj[u]) {
        if (vis[v] >= 0) {
            if (vis[v] == b) return 0;
        }
        else if (!dfs(v, x, y, b ^ 1)) return 0;
    }
    return 1;
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < N; i ++) pw[i] = 2 * pw[i-1] % mod;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) vis[i] = -1, adj[i].clear();
        for (int i = 0, u, v; i < m; i ++) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 1;
        for (int i = 1, x, y; i <= n; i ++) {
            if (vis[i] < 0) {
                x = y = 0;
                if (dfs(i, x, y)) {
                    ans = 1ll * ans * (pw[x] + pw[y]) % mod;
                }
                else ans = 0;
            }
        }
        printf("%d\n", ans);
    }
}