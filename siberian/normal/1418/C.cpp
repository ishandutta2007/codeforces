#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<vector<int>> dp(n + 1, vector<int> (2, n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int it = 0; it <= 1; ++it) {
            for (int prev = max(0, i - 2); prev < i; ++prev) {
                int fans = 0;
                for (int x = prev + 1; x <= i; ++x) {
                    fans += a[x - 1];     
                }
                fans *= it;
                chkmin(dp[i][it], dp[prev][it ^ 1] + fans);
            }
        }
    }
  /*  cout << "dp = " << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << min(dp[n][0], dp[n][1]) << "\n";
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