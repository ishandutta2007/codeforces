#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> y(n);
    for (auto& i : y) {
        cin >> i;
    }
    sort(all(a));
    vector<int> dp(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = upper_bound(all(a), a[i] + k) - (a.begin() + i);
        if (i != n - 1) {
            chkmax(dp[i], dp[i + 1]);
        }
        chkmax(ans, dp[i]);
        int cnt = (a.begin() + i) - lower_bound(all(a), a[i] - k);
        ++cnt;
        chkmax(ans, cnt);
        if (i != n - 1) {
            chkmax(ans, cnt + dp[i + 1]);
        }
    }
    cout << ans << endl;
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