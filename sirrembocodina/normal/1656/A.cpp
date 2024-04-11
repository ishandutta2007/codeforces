#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct my_hash {
    inline size_t operator()(const pair<int, int>& a) const {
        return a.first * 31 + a.second;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[mn] > a[i]) {
                mn = i;
            }
            if (a[mx] < a[i]) {
                mx = i;
            }
        }
        cout << mn + 1 << ' ' << mx + 1 << '\n';
    }
    return 0;
}