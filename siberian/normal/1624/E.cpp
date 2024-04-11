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
    int to;
    int l, r, i;
    Edge() {}
    Edge(int _l, int _r, int _i) {
        l = _l, r = _r, i = _i;
    }
};

vector<vector<Edge>> g;
vector<pair<int, Edge>> par;

void dfs(int v) {
    for (auto [to, l, r, i] : g[v]) {
        if (par[to].first != -1) continue;
        par[to] = {v, {l, r, i}};
        dfs(to);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(m + 1, {});
    map<string, Edge> has;
    for (int i = 1; i <= n; ++i) {
        string a;
        cin >> a;
        for (int l = 0; l < m; ++l) {
            for (int r = l + 1; r <= l + 2 && r < m; ++r) {
                has[a.substr(l, r - l + 1)] = Edge(l + 1, r + 1, i);
            }
        }
    }

    string s;
    cin >> s;
    for (int l = 0; l < m; ++l) {
        for (int r = l + 1; r <= l + 2 && r < m; ++r) {
            string now = s.substr(l, r - l + 1);
            auto it = has.find(now);
            if (it == has.end()) continue;
            Edge edge = it->second;
            edge.to = r + 1; 
            g[l].push_back(edge);    
        }
    }
    par.assign(m + 1, mp(-1, Edge()));
    dfs(0);
    if (par[m].first == -1) {
        cout << "-1\n";
        return;
    }
    int cur = m;
    vector<Edge> ans;
    while (cur != 0) {
        ans.push_back(par[cur].second);
        cur = par[cur].first;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto [to, l, r, i] : ans) {
        cout << l << " " << r << " " << i << '\n';
    }
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