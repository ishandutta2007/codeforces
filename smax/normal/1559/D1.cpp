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

    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU dsu1(n), dsu2(n);
    for (int i=0; i<m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu1.unite(u, v);
    }
    for (int i=0; i<m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu2.unite(u, v);
    }

    vector<pair<int, int>> ret;
    for (int u=0; u<n; u++)
        for (int v=u+1; v<n; v++)
            if (!dsu1.same(u, v) && !dsu2.same(u, v)) {
                dsu1.unite(u, v);
                dsu2.unite(u, v);
                ret.emplace_back(u, v);
            }

    cout << ret.size() << "\n";
    for (auto [u, v] : ret)
        cout << u + 1 << " " << v + 1 << "\n";

    return 0;
}