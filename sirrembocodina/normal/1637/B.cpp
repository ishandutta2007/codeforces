#include <bits/stdc++.h>
#define int long long

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
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r <= n; r++) {
                for (int i = l; i < r; i++) {
                    ans++;
                    ans += a[i] == 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}