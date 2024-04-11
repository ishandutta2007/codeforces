#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mn = 2e9;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != mn) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}