#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mx = a[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i - 1]) {
                mx = max(mx, a[i]);
                continue;
            }
            ans += a[i - 1] - a[i];
        }
        cout << ans << endl;
    }
}