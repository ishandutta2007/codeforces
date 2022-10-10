#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        forn (i, n) {
            cin >> a[i];
            if (a[i] >= k) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }
        vector<int> sum(n + 1);
        forn (i, n) {
            sum[i + 1] = b[i] + sum[i];
        }
        vector<int> pref(n + 1);
        forn (i, n) {
            pref[i + 1] = min(pref[i], sum[i + 1]);
        }
        vector<int> suf(n + 1, sum[n]);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = max(suf[i + 1], sum[i]);
        }
        bool ok = false;
        bool was = false;
        forn (i, n) {
            if (a[i] == k) {
                was = true;
            }
            if (i > 0 && suf[i + 1] - pref[i - 1] > 0) {
                ok = true;
            }
            if (i < n - 1 && suf[i + 2] - pref[i] > 0) {
                ok = true;
            }
        }
        if (!was) {
            cout << "no" << endl;
            continue;
        }
        if (n == 1 && a[0] == k) {
            ok = true;
        }
        if (ok) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}