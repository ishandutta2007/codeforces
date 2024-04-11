#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
ll val[MAXN], up[MAXN], dn[MAXN];
vector<int> adj[MAXN];

void pre(int s, int p = 0) {
    int sz = adj[s].size();
    for(auto &v : adj[s])
        if(v == p) swap(v, adj[s][sz - 1]);
    if(p)
        adj[s].pop_back();
    for(auto v : adj[s])
        pre(v, s);
}

void dfs(int s) {
    for(auto v : adj[s])
        dfs(v);
    if(adj[s].empty()) {
        up[s] = -val[s] * (val[s] < 0);
        dn[s] = val[s] * (val[s] > 0);
        return;
    }
    for(auto v : adj[s]) {
        up[s] = max(up[s], up[v]);
        dn[s] = max(dn[s], dn[v]);
    }
    val[s] += up[s];
    val[s] -= dn[s];
    up[s] -= val[s] * (val[s] < 0);
    dn[s] += val[s] * (val[s] > 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    pre(1);
    dfs(1);
    cout << up[1] + dn[1] << '\n';
}