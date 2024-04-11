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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2 * n, 0));
    for (int i = 0; i < 2 * n; ++i) vin(a[i]);
    vector<pair<int, int>> has = {{0, n}, {n, 0}, {n - 1, n},{n, n - 1}, {2 * n - 1, 0}, {0, 2 * n - 1}, {2 * n - 1, n - 1}, {n- 1, 2 * n - 1}};
    assert(has.size() == 8);
    int ans = 0;
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            ans += a[i][j];
        }
    }
    int val = INT_MAX;
    for (auto [x, y] : has) {
        chkmin(val, a[x][y]);
    }
    cout << ans + val << '\n';
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