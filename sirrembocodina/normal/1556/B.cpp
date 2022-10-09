#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int odd = 0;
        for (int& x: a) {
            cin >> x;
            if (x % 2) {
                odd++;
            }
        }
        int ans = 2e18;
        if ((n + 1) / 2 == odd) {
            int cur = 0;
            int ind = 0;
            forn (i, n) {
                if (a[i] % 2) {
                    cur += abs(ind - i);
                    ind += 2;
                }
            }
            ans = min(ans, cur);
        }
        if (n / 2 == odd) {
            int cur = 0;
            int ind = 1;
            forn (i, n) {
                if (a[i] % 2) {
                    cur += abs(ind - i);
                    ind += 2;
                }
            }
            ans = min(ans, cur);
        }
        if (ans == 2e18) {
            ans = -1;
        }
        cout << ans << '\n';
    }
}