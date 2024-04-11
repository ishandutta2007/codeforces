#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k > (n - 1) / 2) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans(n);
        for (int i = 0; i < k; i++) {
            ans[1 + 2 * i] = n - i;
        }
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                ans[i] = cur;
                cur++;
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}