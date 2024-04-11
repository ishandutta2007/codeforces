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
        int last = 1, cur = 1, ans = 1;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i - 1]) {
                cur++;
                continue;
            }
            last--;
            if (last == 0) {
                last = cur;
                ans++;
                cur = 1;
            } else {
                cur++;
            }
        }
        cout << ans << endl;
    }
}