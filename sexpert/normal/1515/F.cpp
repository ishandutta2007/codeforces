#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 3e5 + 10;
vector<ii> edges;
vector<int> adj[MAXN], ops;
int rep[MAXN], n, m;
ll w[MAXN], x;

int find(int u) {
    return rep[u] ? rep[u] = find(rep[u]) : u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> x;
    set<pair<ll, int>> q;
    ll tot = 0;

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        tot += w[i];
        q.insert({-w[i], i});
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    if(tot < x * (n - 1)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    while(q.size() > 1) {
        auto [W, s] = *q.begin();
        q.erase(q.begin());
        auto [u, v] = edges[adj[s].back()];
        while(find(u) == find(v)) {
            adj[s].pop_back();
            u = edges[adj[s].back()][0];
            v = edges[adj[s].back()][1];
        }
        ops.push_back(adj[s].back());
        adj[s].pop_back();
        int t = (find(u) == s ? find(v) : find(u));
        if(adj[t].size() > adj[s].size())
            swap(s, t);
        q.erase({-w[t], t});
        q.erase({-w[s], s});
        w[s] += w[t];
        w[s] -= x;
        rep[t] = s;
        q.insert({-w[s], s});
        for(auto &id : adj[t])
            adj[s].push_back(id);
        adj[t].clear();
    }

    for(auto &id : ops)
        cout << id + 1 << '\n';
}