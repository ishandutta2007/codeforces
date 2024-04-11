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

const int MAX = 1e6 + 5;

int lp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(lp, lp + MAX, 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p)
            for (int i=p; i<MAX; i+=p)
                lp[i] = p;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<pair<int, int>> ones;
    DSU dsu(MAX + n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        int f = 0;
        vector<int> pf;
        for (int x : {a[i], a[i] + 1}) {
            while (x > 1) {
                int p = lp[x];
                if (f == 0) dsu.unite(MAX + i, p);
                pf.push_back(p);
                while (x % p == 0)
                    x /= p;
            }
            f++;
        }
        for (int x : pf)
            for (int y : pf)
                ones.emplace_back(x, y);
    }
    set<pair<int, int>> st;
    for (auto [x, y] : ones) {
        st.emplace(dsu.find(x), dsu.find(y));
        st.emplace(dsu.find(y), dsu.find(x));
    }

    for (int i=0; i<q; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        if (dsu.same(MAX + s, MAX + t)) cout << "0\n";
        else if (st.count({dsu.find(MAX + s), dsu.find(MAX + t)})) cout << "1\n";
        else cout << "2\n";
    }

    return 0;
}