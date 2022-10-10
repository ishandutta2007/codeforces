#include <bits/stdc++.h>
#define sz(x) (int)(x.size())
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

vector<vector<ii>> adj;

vi eulerWalk(vector<vector<ii>>& gr, int nedges, int src=0) {
    int n = sz(gr);
    vi D(n), its(n), eu(nedges), ret, s = {src};
    //D[src]++; // to allow Euler paths, not just cycles
    while (!s.empty()) {
        int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
        if (it == end){ ret.push_back(x); s.pop_back(); continue; }
        tie(y, e) = gr[x][it++];
        if (!eu[e]) {
            D[x]--, D[y]++;
            eu[e] = 1; s.push_back(y);
        }}
    for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
    return {ret.rbegin(), ret.rend()};
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    vector<int> od;
    for(int i = 0; i < n; i++)
        if(adj[i].size() % 2)
            od.push_back(i);

    for(int i = 0; i < od.size(); i += 2) {
        adj[od[i]].push_back({od[i + 1], m});
        adj[od[i + 1]].push_back({od[i], m});
        m++;
    }

    if(m % 2) {
        adj[0].push_back({0, m});
        m++;
    }
    cout << m << '\n';
    auto v = eulerWalk(adj, m, 0);
    for(int i = 0; i < m; i++) {
        if(i % 2)
            cout << v[i] + 1 << " " << v[i + 1] + 1 << '\n';
        else
            cout << v[i + 1] + 1 << " " << v[i] + 1 << '\n';
    }
}