#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != i + 1) {
                ok = false;
            }
        }
        if (ok) {
            cout << "0\n";
            continue;
        }
        if (a[0] == 1 || a[n - 1] == n) {
            cout << "1\n";
            continue;
        }
        if (a[0] == n && a[n - 1] == 1) {
            cout << "3\n";
            continue;
        }
        cout << "2\n";
    }
}