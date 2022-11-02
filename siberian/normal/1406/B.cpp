#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll
const int INF = LONG_LONG_MAX;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (5, {INF, -INF}));
    for (int i = 0; i < n; i++) {
        dp[i][0][0] = dp[i][0][1] = a[i];
        if (i > 0) {
            chkmin(dp[i][0][0], dp[i - 1][0][0]);
            chkmax(dp[i][0][1], dp[i - 1][0][1]);
            for (int cnt = 1; cnt < 5; cnt++) {
                dp[i][cnt][0] = dp[i - 1][cnt][0];
                dp[i][cnt][1] = dp[i - 1][cnt][1];
                if (dp[i - 1][cnt - 1][0] != INF) {
                    chkmin(dp[i][cnt][0], dp[i - 1][cnt - 1][0] * a[i]);
                    chkmin(dp[i][cnt][0], dp[i - 1][cnt - 1][1] * a[i]);
                    chkmax(dp[i][cnt][1], dp[i - 1][cnt - 1][0] * a[i]);
                    chkmax(dp[i][cnt][1], dp[i - 1][cnt - 1][1] * a[i]);
                }
            }
        }
    }
    cout << dp[n - 1][4][1] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}