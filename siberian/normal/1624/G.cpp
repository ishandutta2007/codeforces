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

struct Edge{
    int u, v, val;
};

struct Dsu{
    int n;
    vector<int> par;
    int comps;
    Dsu(int _n) {
        n = _n;
        comps = n;
        par.resize(n);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (par[v] == v) return v;
        return par[v] = getPar(par[v]);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a != b) {
            par[a] = b;
            comps--;
        }
    }
};

int solve(int bit, vector<Edge> edges, Dsu dsu) {
    if (bit == -1) return 0;
    Dsu cpy = dsu;
    for (auto [u, v, val] : edges) {
        if ((val >> bit) & 1) continue;
        cpy.uni(u, v);
    }
    int ans = 0;
    if (cpy.comps != 1) {
        ans |= (1 << bit);
    } else {
        vector<Edge> new_edges;
        for (auto& [u, v, val] : edges) {
            if ((val >> bit) & 1) continue;
            new_edges.push_back({u, v, val});
        }
        edges = new_edges;
    }
    return ans | solve(bit - 1, edges, dsu);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [u, v, val] : edges) {
        cin >> u >> v >> val;
        --u;
        --v;
    }
    Dsu dsu(n);
    cout << solve(30, edges, dsu) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}