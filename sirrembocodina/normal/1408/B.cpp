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
        int cnt = 0;
        forn (i, n) {
            cin >> a[i];
            if (i) {
                a[i - 1] = a[i] - a[i - 1];
                cnt += a[i - 1] != 0;
            }
        }
        n--;
        k--;
        if (k == 0) {
            if (cnt == 0) {
                cout << 1 << endl;
                continue;
            }
            cout << -1 << endl;
            continue;
        }
        cout << max(1ll, (cnt + k - 1) / k) << endl;
    }
}