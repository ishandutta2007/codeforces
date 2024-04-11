#include <bits/stdc++.h>
using namespace std;

#define N 250250
#define K 20

int n, dep[N], rt[N], fa[N][K];
vector <int> adj[N], tadj[N];

int rnk[N];

int find_rt(int u) {
    while (u != rt[u]) u = rt[u];
    return u;
}

void link(int u, int v) {
    u = find_rt(u), v = find_rt(v);

    if (rnk[u] > rnk[v]) rt[v] = u;
    else if (rnk[u] < rnk[v]) rt[u] = v;
    else rt[u] = v, rnk[v] ++;
}

void dfs(int u, int pa = 0) {
    dep[u] = dep[pa] + 1;
    int k = __lg(dep[u]);
    fa[u][0] = pa;
    for (int i = 1; i <= k; i ++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for (auto v : adj[u]) if (v != pa) dfs(v, u);
}

int anc(int u, int k) {
    if (!k) return u;
    for (int i = __lg(k); ~i; i --) if (k >> i & 1) u = fa[u][i];
    return u;
}

typedef pair <int, int> pii;

int C;

inline bool comp(int u) {
    return find_rt(u) == C;
}

pii solve(int u, int v) {
    for (int i = __lg(dep[u] - dep[v]); ~i; i --) {
        int w = fa[u][i];
        if (dep[w] <= dep[v]) continue;
        if (comp(w) == comp(u)) u = w;
        else v = w;
    }
    assert(dep[u] == dep[v] + 1);
    return pii(u, v);
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    v = anc(v, dep[v] - dep[u]);
    if (u == v) return u;
    for (int i = __lg(dep[u]); ~i; i --) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

pii find_edge(int u, int v) {
    int w = lca(u, v);
    if (comp(w) == comp(v)) return solve(u, w);
    else return solve(v, w);
}

void dfs_solve(int u, int pa = 0) {
    for (auto v : tadj[u]) {
        if (v == pa) continue;
        dfs_solve(v, u); C = find_rt(v);
        pii p = find_edge(u, v);
        printf("%d %d %d %d\n", p.first, p.second, u, v);
        link(p.first, p.second);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) scanf("%d %d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
    for (int i = 1, u, v; i < n; i ++) scanf("%d %d", &u, &v), tadj[u].push_back(v), tadj[v].push_back(u);
    for (int i = 1; i <= n; i ++) rt[i] = i;
    dfs(1);
    printf("%d\n", n - 1);
    dfs_solve(1);

    return 0;
}