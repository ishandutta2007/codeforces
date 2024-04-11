#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

const int N = 1e5 + 10;
int n;
int c[N];
vector<int> g[N];

struct Item{
    unordered_map<int, int> values;
    int maxVal = -1;
    ll sumMax = 0;
    Item() {}
    void addValue(int val, int cnt) {
        assert(cnt > 0);
        values[val] += cnt;
        int cur = values[val];
        if (cur > maxVal) {
            maxVal = cur;
            sumMax = val;
        } else if (cur == maxVal) {
            sumMax += val;
        }
    }
    ll getAns() const {
        return sumMax;
    }
};

int sz[N];

void dfsSz(int v, int p) {
    sz[v] = 1;
    for (auto i : g[v]) {
        if (i == p) continue;
        dfsSz(i, v);
        sz[v] += sz[i];
    }
    auto it = find(all(g[v]), p);
    if (it != g[v].end()) {
        g[v].erase(it);
    }
    sort(all(g[v]), [&] (int i, int j) {
        return sz[i] > sz[j];
    });
}

ll ans[N];

Item dfs(int v) {
    if (g[v].empty()) {
        Item cur;
        cur.addValue(c[v], 1);
        ans[v] = cur.getAns();
        return cur;
    } else {
        auto cur = dfs(g[v][0]);
        cur.addValue(c[v], 1);
        for (int i = 1; i < g[v].size(); ++i) {
            int to = g[v][i];
            auto has = dfs(to);
            for (const auto& [key, value] : has.values) {
                cur.addValue(key, value);
            }
        }
        ans[v] = cur.getAns();
        return cur;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsSz(0, -1);
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}