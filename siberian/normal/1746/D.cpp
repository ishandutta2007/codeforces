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

const int N = 2e5 + 10;
int n, k;
vector<int> g[N];
int s[N];

map<pair<int, int>, ll> dp;

ll solve(int v, int k) {
    if (k == 0) {
        return 0;
    }
    if (dp.count(mp(v, k))) {
        return dp[mp(v, k)];
    }
    ll& ans = dp[mp(v, k)];
    if (g[v].empty()) {
        return ans = (ll)s[v] * k;
    } else {
        int sz = g[v].size();
        int small = k / sz;
        int big = (k + sz - 1) / sz;
        ll total_small = 0;
        vector<ll> diff;
        diff.reserve(sz);
        for (auto to : g[v]) {
            ll small_ans = solve(to, small);
            ll big_ans = solve(to, big);
            total_small += small_ans;
            diff.push_back(big_ans - small_ans);
        }
        sort(all(diff));
        reverse(all(diff));
        int cnt_big = k % sz;
        ll total_big = 0;
        for (int i = 0; i < cnt_big; ++i) {
            total_big += diff[i];
        }
        return ans = (ll)s[v] * k + total_small + total_big;
    }
}

void solve() {
    cin >> n >> k;
    fill(g, g + n, vector<int>());
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    dp.clear();
    cout << solve(0, k) << '\n';
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