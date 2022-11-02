#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Dsu{
    vector<int> par;
    Dsu() {}
    Dsu(int n) {
        par.assign(n, 0);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = getPar(par[v]);
    }
    bool connected(int a, int b) {
        return getPar(a) == getPar(b);
    }
    void uni(int a, int b) {
        // cerr << "par = " << endl;
        // for (auto i : par) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        // cerr << "a = " << a << " b = " << b << endl; 
        par[getPar(a)] = getPar(b);
    }
};

struct Edge{
    int u, v, value;
};

struct Query{
    int a, b, p;
};

int n, q;
vector<vector<int>> g;
vector<Edge> edges;
vector<Query> queries;
bool ok;

int popcount(int x) {
    return __builtin_popcount(x);
}

vector<int> color;
vector<int> used;

void dfs(int v, int u, int c) {
    used[v] = u;
    color[v] = c;
    for (auto i : g[v]) {
        if (used[i] == used[v]) {
            ok = false;
            return;
        }
        if (used[i]) continue;
        dfs(i, 3 - u, c);
        if (!ok) return;
    }
}

vector<int> val;
vector<vector<pair<int, int>>> ng;

void dfsPar(int v, int p) {
    for (auto [to, value] : ng[v]) {
        if (to == p) continue;
        val[to] = val[v] ^ value;
        dfsPar(to, v);
    }
}



void check() {
    val.assign(n, 0);
    ng.assign(n, {});
    for (auto [u, v, value] : edges) {
        ng[u].push_back({v, value});
        ng[v].push_back({u, value});
    }
    dfsPar(0, -1);
    for (auto [a, b, p] : queries) {
        assert(popcount(val[a] ^ val[b]) % 2 == p);
    }
}

// int id;

void solve() {
    cin >> n >> q;
    // cerr << n << " " << q << endl;
    Dsu dsu(n);
    edges.resize(n - 1);
    for (auto& [u, v, value] : edges) {
        cin >> u >> v >> value;
        // cerr << u << " " << v << " " << value << endl;
        --u;
        --v;
        if (value == -1) continue;
        if (popcount(value) % 2 == 0) {
            dsu.uni(u, v);
        } 
    }

    queries.resize(q);
    for (auto& [a, b, p] : queries) {
        cin >> a >> b >> p;
        // cerr << a << " " << b << " " << p << endl;
        --a;
        --b;
        if (p == 0) {
            dsu.uni(a, b);
        }
    }

    g.assign(n, vector<int>());
    for (auto& [u, v, value] : edges) {
        if (value == -1) continue;
        if (popcount(value) % 2 == 1) {
            int vu = dsu.getPar(u);
            int vv = dsu.getPar(v);
            g[vv].push_back(vu);
            g[vu].push_back(vv);
        }
    }
    for (auto& [a, b, p] : queries) {
        if (p == 1) {
            int vu = dsu.getPar(a);
            int vv = dsu.getPar(b);
            g[vv].push_back(vu);
            g[vu].push_back(vv);       
        }
    }
    used.assign(n, 0);
    color.assign(n, -1);
    ok = true;
    int c = 0;
    for (int i = 0; i < n && ok; ++i) {
        if (used[i]) {
            continue;
        }
        dfs(i, 1, c++);
    }
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto& [u, v, value] : edges) {
            if (value != -1) {
                cout << u + 1 << " " << v + 1 << " " << value << '\n';
            } else {
                cout << u + 1 << " " << v + 1 << " ";
                if (used[dsu.getPar(u)] == used[dsu.getPar(v)]) {
                    value = 0;
                    cout << 0;
                } else{
                    value = 1;
                    cout << 1;
                }
                cout << '\n';
            }
        }
        // cout.flush();
        check();
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        // ++id;
        // cerr << "id = " << id << endl;
        solve();
    }
    return 0;
}