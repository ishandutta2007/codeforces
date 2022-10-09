#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int sum = 0;
        for (int i = 0; i <= n; sum += a[i], i++) {
            int cur = sum - k * i;
            int p = 2;
            for (int j = i; j < n && p <= 1e9; j++, p *= 2) {
                cur += a[j] / p;
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}