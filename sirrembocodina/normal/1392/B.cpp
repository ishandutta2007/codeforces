#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int mx = -2e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(a[i], mx);
        }
        for (int i = 0; i < n; i++) {
            a[i] = mx - a[i];
        }
        mx = -2e9;
        for (int i = 0; i < n; i++) {
            mx = max(a[i], mx);
        }
        k--;
        if (k % 2) {
            for (int i = 0; i < n; i++) {
                a[i] = mx - a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}