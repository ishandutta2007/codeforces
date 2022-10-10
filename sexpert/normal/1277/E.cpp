#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int comp[MAXN], vis[MAXN], nc, a, b;

void dfs1(int u, int cc) {
    comp[u] = cc;
    for(auto v : adj[u]) {
        if(comp[v] || v == a)
            continue;
        dfs1(v, cc);
    }
}

void dfs2(int u) {
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(v == b || vis[v])
            continue;
        dfs2(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m >> a >> b;
    nc = 0;
    for(int i = 1; i <= n; i++) {
        comp[i] = 0;
        adj[i].clear();
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 1; u <= n; u++) {
        if(u == a || comp[u])
            continue;
        ++nc;
        dfs1(u, nc);
    }
    int f1 = 0, f2 = 0;
    for(int u = 1; u <= n; u++) {
        if(u != a && comp[u] != comp[b])
            f1++;
    }
    fill(vis, vis + n + 1, 0);
    dfs2(a);
    for(int u = 1; u <= n; u++) {
        if(u != b && comp[u] == comp[b] && !vis[u])
            f2++;
    }
    cout << (ll)f1 * f2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}