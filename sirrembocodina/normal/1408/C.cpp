#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, len;
        cin >> n >> len;
        vector<int> x(n + 2);
        forn (i, n) {
            cin >> x[i + 1];
        }
        x[n + 1] = len;
        vector<long double> a(n + 2), b(n + 2);
        forn (i, n + 1) {
            a[i + 1] = a[i] + (x[i + 1] - x[i]) / (long double)(i + 1);
        }
        for (int i = n; i >= 0; i--) {
            b[i] = b[i + 1] + (x[i + 1] - x[i]) / (long double)(n + 1 - i);
        }
        long double l, r;
        int ind = -1;
        forn (i, n + 2) {
            if (a[i] >= b[i]) {
                l = max(a[i - 1], b[i]);
                r = min(a[i], b[i - 1]);
                ind = i;
                break;
            }
        }
        forn (q, 60) {
            long double mid = (l + r) / 2;
            if (x[ind - 1] + (mid - a[ind - 1]) * ind > x[ind] - (mid - b[ind]) * (n + 2 - ind)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout.precision(15);
        cout << fixed << l << endl;
    }
}