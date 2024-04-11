#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    a[0] = -2e9;
    a[n + 1] = 2e9;
    forn (i, n) {
        cin >> a[i + 1];
        a[i + 1] -= i;
    }
    vector<int> b(k + 2);
    b[0] = 0;
    b[k + 1] = n + 1;
    forn (i, k) {
        cin >> b[i + 1];
    }
    int ans = 0;
    forn (ind, k + 1) {
        int l = b[ind] + 1, r = b[ind + 1];
        int mn = a[b[ind]], mx = a[b[ind + 1]];
        if (mn > mx) {
            cout << -1 << endl;
            return 0;
        }
        vector<int> c;
        for (int i = l; i < r; i++) {
            if (a[i] < mn || a[i] > mx) {
                continue;
            }
            int j = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j == c.size()) {
                c.push_back(a[i]);
            } else {
                c[j] = a[i];
            }
        }
        ans += r - l - c.size();
    }
    cout << ans << endl;
}