#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct DSU {
    vector<int> par, sz, toll;
    vector<pair<int, int>> mx;

    DSU(int n) : par(n), sz(n, 1), toll(n), mx(n) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v, int w) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        if (mx[u].first < mx[v].first)
            toll[u] = toll[v];
        else if (mx[u].first == mx[v].first)
            toll[u] = max({toll[u], toll[v], w});
        mx[u] = max(mx[u], mx[v]);
        return true;
    }
};

const int LOG = 18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> e(n);
    for (int i=0; i<n; i++)
        cin >> e[i];
    vector<vector<pair<int, int>>> adj(n);
    vector<array<int, 3>> edges;
    for (int i=0; i<n-1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--, b--;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
        edges.push_back({c, a, b});
    }
    vector<array<int, 3>> queries;
    for (int i=0; i<q; i++) {
        int v, x;
        cin >> v >> x;
        x--;
        queries.push_back({v, x, i});
    }

    sort(edges.rbegin(), edges.rend());
    sort(queries.rbegin(), queries.rend());
    DSU dsu(n);
    for (int i=0; i<n; i++)
        dsu.mx[i] = {e[i], i};

    vector<int> depth(n);
    vector<vector<int>> up(LOG, vector<int>(n, -1)), mx(LOG, vector<int>(n));

    auto dfs = [&] (auto &self, int u) -> void {
        for (auto [v, w] : adj[u])
            if (v != up[0][u]) {
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                mx[0][v] = w;
                self(self, v);
            }
    };

    dfs(dfs, 0);
    for (int i=1; i<LOG; i++)
        for (int j=0; j<n; j++)
            if (up[i-1][j] != -1) {
                up[i][j] = up[i-1][up[i-1][j]];
                mx[i][j] = max(mx[i-1][j], mx[i-1][up[i-1][j]]);
            }

    auto query = [&] (int u, int v) -> int {
        int ret = 0;
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i=LOG-1; i>=0; i--)
            if (depth[u] - (1 << i) >= depth[v]) {
                ret = max(ret, mx[i][u]);
                u = up[i][u];
            }
        if (u == v)
            return ret;
        for (int i=LOG-1; i>=0; i--)
            if (up[i][u] != up[i][v]) {
                ret = max({ret, mx[i][u], mx[i][v]});
                u = up[i][u];
                v = up[i][v];
            }
        return max({ret, mx[0][u], mx[0][v]});
    };

    int j = 0;
    vector<pair<int, int>> ret(q);
    for (auto [v, x, i] : queries) {
        while (j < n - 1 && edges[j][0] >= v) {
            dsu.unite(edges[j][1], edges[j][2], query(dsu.mx[dsu.find(edges[j][1])].second, dsu.mx[dsu.find(edges[j][2])].second));
            j++;
        }
        ret[i] = {dsu.mx[dsu.find(x)].first, max(dsu.toll[dsu.find(x)], query(x, dsu.mx[dsu.find(x)].second))};
    }

    for (auto [x, y] : ret)
        cout << x << " " << y << "\n";

    return 0;
}