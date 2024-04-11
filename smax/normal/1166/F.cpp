#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

template<int SZ>
struct DSU {
    int par[SZ];
    set<int> nei[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            nei[i].clear();
        }
    }

    int findRoot(int u) {
        if (u != par[u])
            par[u] = findRoot(par[u]);
        return par[u];
    }

    bool unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v)
            return false;
        if (nei[u].size() < nei[v].size())
            swap(u, v);
        par[v] = u;
        nei[u].insert(nei[v].begin(), nei[v].end());
        return true;
    }
};

DSU<100005> ds;
map<int, int> mp[100005];

void addEdge(int x, int y, int z) {
    if (mp[x].count(z))
        ds.unite(y, mp[x][z]);
    if (mp[y].count(z))
        ds.unite(x, mp[y][z]);
    mp[x][z] = y;
    mp[y][z] = x;
    ds.nei[ds.findRoot(x)].insert(y);
    ds.nei[ds.findRoot(y)].insert(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, q;
    cin >> n >> m >> c >> q;
    ds.init(n);
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        addEdge(x, y, z);
    }
    for (int i=0; i<q; i++) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        x--, y--;
        if (t == '+') {
            int z;
            cin >> z;
            addEdge(x, y, z);
        } else {
            x = ds.findRoot(x);
            cout << (x == ds.findRoot(y) || ds.nei[x].count(y) ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}