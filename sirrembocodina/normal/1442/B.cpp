#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> num(n, -1);
        forn (i, k) {
            int x;
            cin >> x;
            x--;
            num[x] = i;
        }
        int ans = 1;
        forn (i, n) {
            if (num[a[i]] == -1) {
                continue;
            }
            int cnt = 0;
            if (i > 0 && num[a[i - 1]] < num[a[i]]) {
                cnt++;
            }
            if (i < n - 1 && num[a[i + 1]] < num[a[i]]) {
                cnt++;
            }
            ans *= cnt;
            ans %= mod;
        }
        cout << ans << endl;
    }
}