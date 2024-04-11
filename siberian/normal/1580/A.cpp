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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, ' '));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            cin >> a[x][y];
        }
    }
    vector<vector<int>> pref(n, vector<int>(m, 0));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            pref[x][y] = a[x][y] - '0';
            if (y > 0) pref[x][y] += pref[x][y - 1];
        }
    }
    auto getPref = [&] (int x, int y1, int y2) -> int {
        return pref[x][y2] - (y1 > 0 ? pref[x][y1 - 1] : 0);
    };
    int ans = n * m;
    for (int y1 = 0; y1 < m; ++y1) {
        for (int y2 = y1 + 3; y2 < m; ++y2) {
            int fans = INT_MAX;
            for (int x = 4; x < n; ++x) {
                int have = 0;
                have += abs(y2 - y1 - 1 - getPref(x - 4, y1 + 1, y2 - 1));
                for (int d = 3; d >= 1; --d) {
                    have += getPref(x - d, y1 + 1, y2 - 1) + (a[x - d][y1] == '0') + (a[x - d][y2] == '0');
                }
                chkmin(fans, have);
                // cerr << "y1 = " << y1 << " y2 = " << y2 << " x = " << x << " have = " << have << endl;
                chkmin(ans, fans + abs(y2 - y1 - 1 - getPref(x, y1 + 1, y2 - 1)));
                fans += getPref(x, y1 + 1, y2 - 1) + (a[x][y1] == '0') + (a[x][y2] == '0');
            }
        }
    }
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