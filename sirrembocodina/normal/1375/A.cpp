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
        forn (i, n) {
            bool x = a[i] < 0;
            if (i % 2 == 1) {
                x = !x;
            }
            cout << a[i] * (x ? -1 : 1) << " ";
        }
        cout << endl;
    }
}