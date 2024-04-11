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
        forn (i, n) {
            cin >> a[i];
        }
        int mn = 1, nxt = a[n - 1];
        bool bad = false;
        for (int i = n - 1; i > 0; i--) {
            if (a[i - 1] == a[i] - 1) {
                continue;
            }
            if (a[i] != mn) {
                bad = true;
                break;
            }
            mn = nxt + 1;
            nxt = a[i - 1];
        }
        if (bad) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}