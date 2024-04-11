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
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        r++;
        int b = 60;
        while ((l & (1ll << b)) == (r & (1ll << b))) {
            b--;
        }
        while (b > 0) {
            b--;
            l |= 1ll << b;
        }
        cout << l << '\n';
    }
}