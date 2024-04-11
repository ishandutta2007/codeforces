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
    int n;
    cin >> n;
    int l = 2 * n - 2, r = 2001 * n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        int h;
        cin >> h;
        if (h != 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = r;
    for (int i = 2; i <= n; i++) {
        cout << "? " << r / i << endl;
        int h;
        cin >> h;
        if (h == 0) {
            continue;
        }
        ans = min(ans, r / i * h);
    }
    cout << "! " << ans << endl;
}