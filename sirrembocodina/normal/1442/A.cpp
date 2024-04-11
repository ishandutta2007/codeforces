#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        int cur_x = 0, cur_y = a[0];
        bool ok = true;
        for (int i = 1; i < n; i++) {
            cur_x = max(cur_x, a[i] - cur_y);
            if (cur_x > a[i]) {
                ok = false;
            }
            cur_y = a[i] - cur_x;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}