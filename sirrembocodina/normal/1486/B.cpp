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
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (n % 2) {
            cout << 1 << endl;
        } else {
            cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << endl;
        }
    }
}