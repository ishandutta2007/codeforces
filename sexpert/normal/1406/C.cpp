#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> sz;
int n;
vector<pair<int, int>> edges;

void dfs(int s, int p = -1) {
    sz[s] = 1;
    for(auto v : adj[s])
        if(v != p) {
            dfs(v, s);
            sz[s] += sz[v];
        }
}

pair<int, int> get_cen(int s, int p = -1) {
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(sz[v] >= (n + 1)/2)
            return get_cen(v, s);
    }
    if(n % 2 == 0 && sz[s] == n / 2)
        return {s, p};
    return {s, -1};
}

void solve() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    edges.resize(n - 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    dfs(1);
    auto p = get_cen(1);

    if(p.second == -1) {
        cout << edges[0].first << " " << edges[0].second << '\n';
        cout << edges[0].first << " " << edges[0].second << '\n';
        return;
    }

    int a = p.first, b = p.second, c = -1;
    for(auto v : adj[a]) {
        if(v != b)
            c = v;
    }
    cout << a << " " << c << '\n';
    cout << b << " " << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}