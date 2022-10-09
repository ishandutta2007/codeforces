#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> used(n);
        bool ok = true;
        forn (i, n) {
            cin >> a[i];
            a[i] = ((i + a[i]) + 1000000000ll * n) % n;
            if (used[a[i]]) {
                ok = false;
            }
            used[a[i]] = true;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}