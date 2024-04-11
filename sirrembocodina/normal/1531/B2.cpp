#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<pair<int, int>, int> c;
    map<int, int> a, b;
    forn (i, n) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            b[x]++;
        } else {
            a[x]++;
            a[y]++;
            c[{min(x, y), max(x, y)}]++;
        }
    }
    int ans = 0;
    for (auto [k, v]: a) {
        ans += v * (v - 1) / 2;
    }
    for (auto [k, v]: c) {
        ans -= v * (v - 1) / 2;
    }
    for (auto [k, v]: b) {
        ans += v * (v - 1) / 2;
        ans += v * a[k];
    }
    cout << ans << endl;
}