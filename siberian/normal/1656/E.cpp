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

int n;
vector<vector<int>> g;
vector<int> ans;

void solve(int v, int p, int need_sum, int up_sum) {
    if (v == p) {
        int cnt = g[v].size();
        int val = cnt;
        assert(val != 0);
        ans[v] = -val;
        for (auto i : g[v]) {
            solve(i, v, 1, (g[v].size() - 1) + ans[v]);
        }
    } else {
        int val = need_sum - up_sum * (g[v].size() - 1);
        ans[v] = val;
        for (auto i : g[v]) {
            if (i == p) {
                continue;
            }
            solve(i, v, up_sum, up_sum * (g[v].size() - 1) + val);
        }
    }
}

vector<int> sz;

void dfs(int v, int p) {
    sz[v] = ans[v];
    for (auto i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        sz[v] += sz[i];
    }
}

void check() {
    cout.flush();
    sz.assign(n, 0);
    for (int v = 0; v < n; ++v) {
        dfs(v, v);
        for (auto i : g[v]) {
            assert(sz[i] == sz[g[v][0]]);
        }
    }
}

void solve() {
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans.assign(n, 0);
    for (int v = 0; v < n; ++v) {
        if (g[v].size() < 2) {
            continue;
        }
        solve(v, v, 0, 0);
        break;
    }    

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << " ";
        }
        assert(ans[i] != 0);
        cout << ans[i];
    }
    cout << '\n';
    // check();
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