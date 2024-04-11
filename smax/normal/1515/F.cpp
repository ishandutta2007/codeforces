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

int x;

struct DSU {
    vector<int> par, sz;
    vector<long long> tot;
    vector<vector<pair<int, int>>> adj;

    DSU(int n) : par(n), sz(n, 1), tot(n), adj(n) {
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
        tot[u] += tot[v] - x;
        assert(tot[u] >= 0);
        if (adj[u].size() < adj[v].size())
            adj[u].swap(adj[v]);
        adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> x;
    long long tot = 0;
    DSU dsu(n);
    multiset<pair<long long, int>> st;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        tot += a;
        dsu.tot[i] = a;
        st.emplace(a, i);
    }
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.adj[u].emplace_back(v, i);
        dsu.adj[v].emplace_back(u, i);
    }

    if (tot < (long long) x * (n - 1)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    while (st.size() > 1) {
        auto [a, u] = *st.rbegin();
        st.erase(prev(st.end()));
        while (true) {
            auto [v, i] = dsu.adj[u].back();
            dsu.adj[u].pop_back();
            v = dsu.find(v);
            long long b = dsu.tot[v];
            if (dsu.unite(u, v)) {
                cout << i + 1 << "\n";
                st.erase(st.find({b, v}));
                st.emplace(dsu.tot[dsu.find(u)], dsu.find(u));
                break;
            }
        }
    }

    return 0;
}