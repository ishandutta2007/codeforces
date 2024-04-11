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
        int n, k;
        cin >> n;
        vector<int> a(n);
        bool one = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                one = true;
            }
        }
        sort(a.begin(), a.end());
        bool dif_one = false;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] + 1 == a[i + 1]) {
                dif_one = true;
            }
        }
        cout << (!one || !dif_one ? "YES\n" : "NO\n");
    }
    return 0;
}