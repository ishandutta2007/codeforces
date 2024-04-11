#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    forn (i, n) {
        cin >> a[i];
        a[i] += mx;
        mx = max(mx, a[i]);
        cout << a[i] << " ";
    }
    cout << endl;
}