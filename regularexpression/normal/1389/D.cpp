#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, l1, r1, l2, r2;
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        int l = max(l1, l2), r = min(r1, r2);
        if (l <= r) {
            if ((r - l) * n >= k) cout << 0; else {
                k -= (r - l) * n;
                int l3 = min(l1, l2), r3 = max(r1, r2);
                int kek = r3 - l3 - (r - l);
                int ans = 4e18;
                for (int i = 1; i <= n; ++i) {
                    int one = i * kek;
                    if (one >= k) ans = min(ans, k); else ans = min(ans, one + (k - one) * 2);
                }
                cout << ans;
            }
        } else {
            int need = l - r;
            int ans = 4e18;
            l = min(l1, l2), r = max(r1, r2);
            for (int i = 1; i <= n; ++i) {
                int one = i * (r - l), now = need * i;
                if (one >= k) {
                    now += k;
                } else now += one + (k - one) * 2;
                ans = min(ans, now);
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}