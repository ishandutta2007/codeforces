#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

struct DSU {
    vector<int> pred, size;

    DSU(int n) {
        pred.resize(n);
        iota(pred.begin(), pred.end(), 0);
        size.resize(n, 1);
    }

    int root(int v) {
        vector<int> stack;
        while (v != pred[v]) {
            stack.push_back(v);
            v = pred[v];
        }
        for (auto x : stack) {
            pred[x] = v;
        }
        return v;
    }

    bool same(int u, int v) {
        return root(u) == root(v);
    }

    void unite(int u, int v) {
        u = root(u);
        v = root(v);
        if (v == u) {
            return;
        }
        if (size[u] < size[v]) {
            pred[u] = v;
            size[v] += size[u];
        } else {
            pred[v] = u;
            size[u] += size[v];
        }
    }
};

struct edge {
    int u;
    int v;
    int c;

    bool operator<(const edge &other) const {
        return c < other.c;
    }
};

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    sort(all(edges));
    int mx = 0;
    DSU dsu(n + 1);
    int cnt = 0;
    for (auto edg : edges) {
        if (edg.c > k) {
            break;
        }
        mx = edg.c;
        if (!dsu.same(edg.u, edg.v)) {
            cnt++;
            dsu.unite(edg.u, edg.v);
        }
    }
    int mn = (int) 1e10;
    for (auto edg : edges) {
        if (edg.c > k) {
            mn = min(mn, edg.c);
        }
    }
    if (cnt == n - 1) {
        cout << min(abs(mx - k), abs(mn - k)) << '\n';
        return;
    }
    int ans = 0;
    for (auto edg : edges) {
        if (edg.c <= k) {
            continue;
        }
        if (!dsu.same(edg.u, edg.v)) {
            cnt++;
            ans += edg.c - k;
            dsu.unite(edg.u, edg.v);
        }
        if (cnt >= n - 1) {
            break;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}