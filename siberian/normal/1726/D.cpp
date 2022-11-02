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
    int u, v, id;
};

struct Dsu{
    int n;
    vector<int> par;
    Dsu() = default;
    Dsu(int _n) : n(_n), par(n, 0) {
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = getPar(par[v]);
    }
    bool isConnected(int a, int b) {
        return getPar(a) == getPar(b);
    }
    bool uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) {
            return false;
        }
        --n;
        par[b] = a;
        return true; 
    }
};

int n, m;
vector<Edge> edges;
vector<Edge> bad;

Dsu cur[2];

int getAns(string& colors) {
    for (const auto& [u, v, id] : edges) {
        for (int color = 0; color < 2; ++color) {
            if (cur[color].isConnected(u, v)) {
                continue;
            }
            cur[color].uni(u, v);
            colors[id] = '0' + color;
            break;
        }
    }
    return cur[0].n + cur[1].n;
}

void solve() {
    cin >> n >> m;
    Dsu dsu(n);
    bad.clear();
    edges.clear();
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (dsu.isConnected(u, v)) {
            bad.push_back({u, v, i});
        } else {
            dsu.uni(u, v);
            edges.push_back({u, v, i});
        }
    }

    pair<int, string> ans(n + 1, string(m, '0'));
    for (int mask = 0; mask < (1 << (int)bad.size()); ++mask) {
        cur[0] = Dsu(n);
        cur[1] = Dsu(n);
        string colors(m, '0');
        for (int bit = 0; bit < (int)bad.size(); ++bit) {
            cur[(mask >> bit) & 1].uni(bad[bit].u, bad[bit].v);
            colors[bad[bit].id] = ((mask >> bit) & 1) + '0';
        }
        int fans = getAns(colors);
        chkmin(ans, mp(fans, colors));
    }
    // cerr << "fans: " << ans.first << endl;
    cout << ans.second << '\n';
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