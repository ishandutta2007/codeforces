#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int cur = 1, ans = 0;
    while ((1LL << cur) * ((1LL << cur) - 1) / 2 <= n) {
        ++ans;
        n -= (1LL << cur) * ((1LL << cur) - 1) / 2;
        ++cur;
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}