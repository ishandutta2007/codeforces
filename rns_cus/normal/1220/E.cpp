#include <bits/stdc++.h>
using namespace std;

#define N 200200

typedef long long ll;

int n, m, deg[N], fa[N];
bool vis[N];
vector <int> vec, adj[N], Adj[N];

int s;
ll w[N];

void dfs(int u) {
    vis[u] = 1; vec.push_back(u);
    for (auto v : adj[u]) if (!vis[v]) dfs(v);
}

ll ans, mx[N];

void Dfs(int u, int pa = -1) {
    mx[u] = 0; fa[u] = pa;
    for (auto v : Adj[u]) {
        if (v == pa || !vis[v]) continue;
        Dfs(v, u);
        mx[u] = max(mx[u], mx[v]);
    }
    mx[u] += w[u];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    while (m --) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) deg[i] = adj[i].size();
    for (int i = 0; i <= n; i ++) fa[i] = -2;
    scanf("%d", &s);
        dfs(s);
        int sz = vec.size();
        if (sz == 1) {
            ans = max(ans, w[vec[0]]);
        }
        else if (sz == 2) {
            ans = max(ans, w[vec[0]] + w[vec[1]]);
        }
        else {
            queue <int> Q;
            for (int j = 0; j < sz; j ++) if (deg[vec[j]] == 1) Q.push(vec[j]);
            for (int j = 0; j < sz; j ++) vis[vec[j]] = 0;
            while (!Q.empty()) {
                int u = Q.front(); Q.pop(); vis[u] = 1;
                for (auto v : adj[u]) if (!vis[v]) {
                    deg[v] --; Adj[v].push_back(u); Adj[u].push_back(v);
                    if (deg[v] == 1) Q.push(v);
                }
            }
            if (!vis[s]) s = 0; vis[0] = 1;
            for (int j = 0; j < sz; j ++) if (!vis[vec[j]]) {
                for (auto x : Adj[vec[j]]) Adj[0].push_back(x), Adj[x].push_back(0);
                w[0] += w[vec[j]];
            }
            Dfs(s); ans = mx[s];
            if (fa[0] > -2) {
                int u = 0;
                ll rlt = 0;
                while (u != -1) {
                    rlt += w[u];
                    w[u] = 0, u = fa[u];
                }
                Dfs(0); rlt += mx[0];
                ans = max(ans, rlt);
            }
        }

    printf("%I64d\n", ans);

    return 0;
}