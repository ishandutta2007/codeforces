#include <bits/stdc++.h>

#define pb push_back
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) cin >> L[i] >> R[i];
        vector<int> L2 = L, R2 = R;
        sort(L2.begin(), L2.end());
        sort(R2.begin(), R2.end());
        int ans = n-1;
        for (int i = 0; i < n; i++) {
            int kek = (int) ((lower_bound(R2.begin(), R2.end(), L[i]) - R2.begin()));
            kek = max(kek, 0);
            int lol = (upper_bound(L2.begin(), L2.end(), R[i]) - L2.begin());
            lol = n - lol;
            lol = max(lol, 0);
            ans = min(ans, kek + lol);
        }
        cout << ans << '\n';
    }
}