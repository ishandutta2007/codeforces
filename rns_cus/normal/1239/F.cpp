#include <bits/stdc++.h>
using namespace std;

#define N 500500

int n, m, deg[N], pa[N], dep[N];
vector <int> ans, adj[N];
int vis[N];

vector <int> cycle;

typedef pair <int, int> pii;

bool dfs(int u, int fa = 0) {
    vis[u] = 1; pa[u] = fa;
    dep[u] = dep[fa] + 1;
    pii mx = pii(0, 0);
    for (auto v : adj[u]) {
        if (v == fa) continue;
        if (vis[v] == 1) mx = max(mx, pii(dep[v], v));
    }
    if (mx.second) {
        cycle.clear();
        int v = mx.second;
        while (u != v) cycle.push_back(u), u = pa[u];
        cycle.push_back(v);
        return 1;
    }
    for (auto v : adj[u]) {
        if (!vis[v] && dfs(v, u)) return 1;
    }
    return 0;
}

bool solve_2() {
    bool fg = 1;
    for (int i = 1; i <= n && fg; i ++) if (!vis[i]) {
        if (dfs(i)) fg = 0;
    }
    if (fg) return 0;
    for (int i = 1; i <= n; i ++) vis[i] = 1;
    for (auto x : cycle) vis[x] = 0;
    for (int i = 1; i <= n; i ++) if (vis[i]) ans.push_back(i);
    return 1;
}

int nxt(int u, int v, int k) {
    assert(adj[u].size() > k + 1);
    if (adj[u][k] == v) swap(adj[u][k], adj[u][k+1]);
    return adj[u][k];
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[v] > dep[u]) v = pa[v];
    while (u != v) u = pa[u], v = pa[v];
    return u;
}

bool solve() {
    for (int i = 1; i <= n; i ++) if (deg[i] % 3 == 0) {
        for (int j = 1; j <= n; j ++) if (j != i) ans.push_back(j);
        return 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) if (deg[i] % 3 == 1) cnt ++;
    if (cnt == 0) {
        if (m == n) return 0;
        solve_2(); return 1;
    }
    if (cnt >= 2) {
        if (cnt == 2 && m == n - 1) return 0;
        int k, d;
        for (k = 1; k <= n; k ++) if (deg[k] % 3 == 1) break;
        queue <int> Q;
        for (int i = 1; i <= n; i ++) dep[i] = 0;
        dep[k] = 1, Q.push(k);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (auto v : adj[u]) if (!dep[v]) {
                dep[v] = dep[u] + 1;
                pa[v] = u;
                if (deg[v] % 3 == 1) {
                    d = v;
                    while (!Q.empty()) Q.pop();
                    break;
                }
                else Q.push(v);
            }
        }
        for (int i = 1; i <= n; i ++) vis[i] = 1;
        while (d != k) vis[d] = 0, d = pa[d]; vis[k] = 0;
        for (int i = 1; i <= n; i ++) if (vis[i]) ans.push_back(i);
        return 1;
    }
    int k;
    for (int i = 1; i <= n; i ++) vis[i] = 0;
    for (k = 1; k <= n; k ++) if (deg[k] % 3 == 1) break;
    vis[k] = 2;
    if (solve_2()) return 1;
    if (m == n + 1 && deg[k] == 4) return 0;
    for (int i = 1; i <= n; i ++) vis[i] = 0;
    assert(dfs(k));
    vector <int> tmp = cycle;
    for (int i = 1; i <= n; i ++) vis[i] = 0;
    vis[k] = 2;
    dfs(tmp[0]);
    for (int i = 1; i <= n; i ++) if (vis[i]) vis[i] = 2;
    vis[k] = 0;
    assert(dfs(k));
    for (int i = 1; i <= n; i ++) vis[i] = 1;
    for (auto x : tmp) vis[x] = 0;
    for (auto x : cycle) vis[x] = 0;
    for (int i = 1; i <= n; i ++) if (vis[i]) ans.push_back(i);
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m); ans.clear();
        for (int i = 1; i <= n; i ++) adj[i].clear();
        if (n == 1) {
            puts("No");
            continue;
        }
        for (int i = 0; i < m; i ++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i ++) vis[i] = 0, deg[i] = adj[i].size();
        if (!solve()) puts("No");
        else {
            puts("Yes");
            printf("%d\n", (int)ans.size());
            for (auto x : ans) printf("%d ", x); puts("");
        }
    }
}