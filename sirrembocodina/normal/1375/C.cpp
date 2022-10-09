#include "bits/stdc++.h"

using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

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
        if (a.back() > a[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}