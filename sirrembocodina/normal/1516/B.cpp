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
        int x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            cout << "YES\n";
            continue;
        }
        int len_pref = -1, len_suf = -1;
        int y = 0;
        for (int i = 0; i < n; i++) {
            y ^= a[i];
            if (y == x) {
                len_pref = i + 1;
                break;
            }
        }
        y = 0;
        for (int i = n - 1; i >= 0; i--) {
            y ^= a[i];
            if (y == x) {
                len_suf = n - i;
                break;
            }
        }
        if (len_suf + len_pref < n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}