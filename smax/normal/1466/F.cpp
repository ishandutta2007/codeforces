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

const int MOD = 1e9 + 7;

template<int SZ>
struct DSU {
    int par[SZ], sz[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
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
        return true;
    }
};

DSU<500005> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    ds.init(m + 1);
    vector<int> ret;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        vector<int> x(k);
        for (int j=0; j<k; j++) {
            cin >> x[j];
            x[j]--;
        }
        if (k == 1)
            x.push_back(m);
        if (ds.unite(x[0], x[1]))
            ret.push_back(i);
    }

    int ways = 1;
    for (int i=0; i<(int)ret.size(); i++)
        ways = ways * 2 % MOD;

    cout << ways << " " << ret.size() << "\n";
    for (int x : ret)
        cout << x + 1 << " ";
    cout << "\n";

    return 0;
}