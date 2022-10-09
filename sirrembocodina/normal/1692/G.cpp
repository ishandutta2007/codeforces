#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 0; i + 1 < n; i++) {
            b.push_back(a[i] < 2 * a[i + 1]);
        }
        vector<int> sum(b.size() + 1);
        for (int i = 0; i < b.size(); i++) {
            sum[i + 1] = sum[i] + b[i];
        }
        int ans = 0;
        for (int l = 0; l + k <= b.size(); l++) {
            if (sum[l + k] - sum[l] == k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}