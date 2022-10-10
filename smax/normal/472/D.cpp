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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    vector<tuple<int, int, int>> edges;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> d[i][j];
            if (i < j) {
                if (d[i][j] == 0) {
                    cout << "NO\n";
                    return 0;
                }
                edges.emplace_back(d[i][j], i, j);
            }
        }

    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<vector<pair<int, int>>> adj(n);
    for (auto [w, u, v] : edges)
        if (dsu.unite(u, v)) {
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

    vector<vector<long long>> dist(n, vector<long long>(n));

    auto dfs = [&] (auto &self, int u, int p, int r) -> void {
        for (auto [v, w] : adj[u])
            if (v != p) {
                dist[r][v] = dist[r][u] + w;
                self(self, v, u, r);
            }
    };

    for (int u=0; u<n; u++)
        dfs(dfs, u, -1, u);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (d[i][j] != dist[i][j]) {
                cout << "NO\n";
                return 0;
            }
    cout << "YES\n";

    return 0;
}