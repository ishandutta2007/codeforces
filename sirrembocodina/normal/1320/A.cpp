#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i] - i] += a[i];
    }
    int mx = 0;
    for (auto& x: m) {
        mx = max(mx, x.second);
    }
    cout << mx << endl;
}