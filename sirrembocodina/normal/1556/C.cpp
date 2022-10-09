#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n -= n % 2;
    vector<int> a(n);
    for (int& x: a) {
        cin >> x;
    }
    unsigned long long ans = 0;
    for (int l = 0; l < n; l += 2) {
        int bres = a[l], bmin = a[l];
        for (int r = l + 1; ; bmin = min(bmin, bres - a[r]), bres += -a[r] + a[r + 1], r += 2) {
            int L = max(0ll, bres - a[r]);
            int R = min(min(bmin, bres - 1), a[l] - 1);
            //cerr << bres << " " << bmin << endl;
            //cerr << L << ' ' << R << endl;
            if (R >= L) {
                ans += (unsigned long long)(R - L + 1);
            }
            if (r + 2 >= n) {
                break;
            }
        }
    }
    cout << ans;
}