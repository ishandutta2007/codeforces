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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

template<int SZ>
struct DSU {
    int par[SZ], sz[SZ], taken[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
            taken[i] = 0;
        }
    }

    int find(int u) {
        if (u != par[u])
            par[u] = find(par[u]);
        return par[u];
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
        taken[u] += taken[v] + 1;
        return true;
    }
};

DSU<200005> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        edges.emplace_back(w, a, b);
    }

    sort(edges.rbegin(), edges.rend());
    ds.init(n);
    int ret = 0;
    for (auto [w, a, b] : edges) {
        if (ds.same(a, b)) {
            // check if any princes is still takeable
            // it is always possible to rearrange the prince matchings to make it work
            int u = ds.find(a);
            if (ds.taken[u] < ds.sz[u]) {
                ds.taken[u]++;
                ret += w;
            }
        } else {
            // take one of the princes, merge the two edge sets together
            int u = ds.find(a), v = ds.find(b);
            if (ds.taken[u] < ds.sz[u] || ds.taken[v] < ds.sz[v]) {
                ds.unite(u, v);
                ret += w;
            }
        }
    }
    cout << ret << "\n";

    return 0;
}