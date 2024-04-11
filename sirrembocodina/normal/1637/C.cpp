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
        bool ok = false;
        if (n == 3) {
            if (a[1] % 2) {
                cout << "-1\n";
                continue;
            }
            cout << a[1] / 2 << '\n';
            continue;
        }
        int odd = 0;
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > 1) {
                ok = true;
            }
            odd += a[i] % 2;
            sum += a[i];
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        //if (odd < n - 2) {
            cout << (sum + odd) / 2 << '\n';
            //continue;
        //}
    }
    return 0;
}