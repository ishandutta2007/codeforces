#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
vector<int> adj[MAXN], tour;
int tin[MAXN], up[MAXN][20], to[MAXN], used[MAXN], h[MAXN], curt, n, m, q;
vector<vector<int>> cliques;

void dfs(int s, int p = 0) {
    tin[s] = ++curt;
    up[s][0] = p ? p : s;
    h[s] = p ? h[p] + 1 : 0;
    tour.push_back(s);
    for(auto v : adj[s]) {
        if(!tin[v])
            dfs(v, s);
    }
}

int lca(int u, int v) {
    if(h[v] > h[u])
        swap(u, v);
    int d = h[u] - h[v];
    for(int l = 19; l >= 0; l--)
        if(d & (1 << l)) u = up[u][l];
    if(u == v)
        return u;
    for(int l = 19; l >= 0; l--) {
        if(up[u][l] != up[v][l]) {
            u = up[u][l];
            v = up[v][l];
        }
    }
    return up[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    auto cmp = [&](int a, int b){
        return tin[a] < tin[b];
    };
    for(int i = 1; i <= n; i++) {
        int fst = *min_element(adj[i].begin(), adj[i].end(), cmp);
        to[i] = fst;
    }
    reverse(tour.begin(), tour.end());
    for(auto i : tour) {
        if(used[i])
            continue;
        int tar = to[i], u = i;
        if(tin[tar] > tin[i])
            continue;
        vector<int> cl;
        used[u] = 1;
        do {
            used[u] = 1;
            cl.push_back(u);
            u = up[u][0];
        } while(u != tar);
        cl.push_back(tar);
        cliques.push_back(cl);
    }
    for(int u = 1; u <= n; u++)
        adj[u].clear();
    for(int i = 0; i < cliques.size(); i++) {
        auto cl = cliques[i];
        for(auto u : cl) {
            adj[u].push_back(n + i + 1);
            adj[n + i + 1].push_back(u);
        }
    }
    memset(tin, 0, sizeof tin);
    dfs(1);
    for(int l = 0; l < 19; l++)
        for(int u = 1; u <= n; u++)
            up[u][l + 1] = up[up[u][l]][l];
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << (h[u] + h[v] - 2*h[lca(u, v)])/2 << '\n';
    }
}