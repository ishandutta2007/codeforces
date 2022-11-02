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

#define int ll

void dfs(int v, vector<bool>& used, int& ans, const vector<vector<int>>& g) {
    ++ans;
    used[v] = true;
    for (auto to : g[v]) {
        if (used[to]) continue;
        dfs(to, used, ans, g);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> pa(n);
    vin(pa);
    vector<int> pb(n);
    vin(pb);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int u = pa[i];
        int v = pb[i];
        --u;
        --v;
        if (u == v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> used(n, false);
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int ans = 0;
        dfs(i, used, ans, g);
        a.push_back(ans);
    }
    sort(all(a));
    // reverse(all(a));
    // cerr << "a = " << endl;
    // for (auto i : a) {
    //     cerr << i << " ";
    // }
    // cerr << endl;

    // int cnt = 0;
    ll ans = 0;

    deque<int> has;
    for (int i = 1; i <= n; ++i) {
        has.push_back(i);
    }

    for (auto val : a) {
        // if (val == 1) continue;
        vector<int> l, r;
        for (int i = 0; i < val / 2; ++i) {
            l.push_back(has[0]);
            has.pop_front();
        }
        for (int i = 0; i < val / 2; ++i) {
            r.push_back(has.back());
            has.pop_back();
        }
        reverse(all(r));
        vector<int> fans;
        reverse(all(l));
        // reverse(all(r));
        while (!l.empty() && !r.empty()) {
            fans.push_back(l.back());
            fans.push_back(r.back());
            l.pop_back();
            r.pop_back();
        }
        while (!l.empty()) {
            fans.push_back(l.back());
            l.pop_back();
        }
        while (!r.empty()) {
            fans.push_back(r.back());
            r.pop_back();
        }
        // cerr << "fans = " << endl;
        // for (auto i : fans) {
        //     cerr << i << " ";
        // }
        // cerr << endl;
        for (int i = 0; i < fans.size(); ++i) {
            ans += abs(fans[i] - fans[(i + 1) % fans.size()]);
        }
    }

    // for (auto val : a) {
    //     if (val == 1) continue;
    //     for (int i = 0; i < val / 2; ++i) {
    //         int cur = cnt + i;
    //         int left = n - 1 - cnt - i;
    //         int right = (i == 0 ? n - 1 - cnt - val / 2 + 1 : n - 1 - cnt + 1 - i);
    //         // if (val == 2) {
    //         //     right = left;
    //         // }
    //         // cerr << "cur = " << cur << " left = " << left << " right = " << right << endl;
    //         ans += abs(cur - left) + abs(cur - right);
    //     }
    //     assert(val % 2 == 0);
    //     cnt += val / 2;
    // }
    cout << ans << '\n';
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