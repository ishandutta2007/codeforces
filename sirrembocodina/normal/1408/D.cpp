#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    forn (i, n) {
        cin >> a[i];
        cin >> b[i];
    }
    forn (i, m) {
        cin >> c[i];
        cin >> d[i];
    }
    vector<int> h(1e6 + 10);
    forn (i, n) {
        forn (j, m) {
            if (a[i] <= c[j] && b[i] <= d[j]) {
                h[c[j] - a[i]] = max(h[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }
    }
    for (int i = h.size() - 2; i >= 0; i--) {
        h[i] = max(h[i], h[i + 1]);
    }
    int ans = 2e9;
    /*forn (i, 10) {
        cout << h[i] << " ";
    }
    cout << endl;*/
    forn (i, h.size()) {
        ans = min(ans, i + h[i]);
    }
    cout << ans << endl;
}