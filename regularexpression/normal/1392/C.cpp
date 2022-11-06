#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            a[i] += ans;
            if (a[i] < a[i - 1]) {
                ans += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}