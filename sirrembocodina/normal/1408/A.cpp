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
        vector<int> b(n);
        vector<int> c(n);
        for (int& x: a) {
            cin >> x;
        }
        for (int& x: b) {
            cin >> x;
        }
        for (int& x: c) {
            cin >> x;
        }
        vector<int> d(n);
        forn (i, n) {
            if (i == 0) {
                d[i] = a[i];
            } else if (i < n - 1) {
                d[i] = a[i] == d[i - 1] ? b[i] : a[i];
            } else {
                d[i] = a[i] == d[i - 1] || a[i] == d[0] ? (b[i] == d[i - 1] || b[i] == d[0] ? c[i] : b[i]) : a[i];
            }
        }
        forn (i, n) {
            cout << d[i] << " ";
        }
        cout << endl;
    }
}