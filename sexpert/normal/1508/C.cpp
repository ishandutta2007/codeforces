#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
int n, m, xo, rep[MAXN], sz[MAXN];
set<int> adj[MAXN], rem;
vector<array<int, 3>> edges;

int find(int u) {
    return rep[u] == 0 ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    if(sz[u] < sz[v])
        swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        xo ^= w;
        if(w == 0)
            w = -1;
        edges.push_back({u, v, w});
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for(int i = 1; i <= n; i++)
        rem.insert(i);

    queue<int> q;
    while(rem.size()) {
        int u = *rem.begin(); rem.erase(rem.begin());
        q.push(u);
        while(q.size()) {
            vector<int> to_rem;
            int u = q.front(); q.pop();
            for(auto &x : rem) {
                if(adj[u].count(x))
                    continue;
                q.push(x);
                to_rem.push_back(x);
                edges.push_back({u, x, 0});
            }
            for(auto &x : to_rem)
                rem.erase(x);
            to_rem.clear();
        }
    }

    sort(edges.begin(), edges.end(), [&](array<int, 3> a, array<int, 3> b){ return a[2] < b[2]; });
    int used = 0;
    ll tot = 0;
    fill(sz, sz + n + 1, 1);
    vector<array<int, 2>> ex;

    for(auto [u, v, w] : edges) {
        if(w == 0)
            ex.push_back({u, v});
        if(join(u, v)) {
            tot += max(w, 0);
            if(w == 0)
                used++;
        }
    }
    if(xo == 0 || used + m < (ll)n * (n - 1)/2LL) {
        cout << tot << '\n';
        return 0;
    }

    ll ans = 1e18;
    for(auto &[uu, vv] : ex) {
        tot = 0;
        bool incl = false;
        fill(rep, rep + n + 1, 0);
        fill(sz, sz + n + 1, 1);
        for(auto [u, v, w] : edges) {
            if(u == uu && v == vv)
                continue;
            if(w >= xo && !incl) {
                incl = true;
                if(join(uu, vv))
                    tot += xo;
            }
            if(join(u, v))
                tot += max(w, 0);
        }
        ans = min(ans, tot);
    }
    cout << ans << '\n';
}