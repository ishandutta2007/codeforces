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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x: a) {
            cin >> x;
        }
        int l = -1, r = -1;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] == a[i + 1]) {
                if (l == -1) {
                    l = i;
                }
                r = i;
            }
        }
        if (l == r) {
            cout << "0\n";
            continue;
        }
        cout << max(1ll, r - l - 1) << "\n";
    }
}