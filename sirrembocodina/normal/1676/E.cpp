#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + a[i];
        }
        while (q--) {
            int x;
            cin >> x;
            int k = lower_bound(sum.begin(), sum.end(), x) - sum.begin();
            if (k == n + 1) {
                cout << "-1\n";
            } else {
                cout << k << '\n';
            }
        }
    }
}