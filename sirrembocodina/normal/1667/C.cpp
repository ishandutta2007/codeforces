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
    n = (2 * n + 1) / 3;
    cout << n << '\n';
    int n_odd = n - (n % 2 == 0);
    for (int i = 0; i < n_odd / 2; i++) {
        cout << i + 1 << ' ' << n_odd / 2 - i << '\n';
    }
    for (int i = 0; i < n_odd / 2 + 1; i++) {
        cout << n_odd / 2 + i + 1 << ' ' << n_odd / 2 + n_odd / 2 + 1 - i << '\n';
    }
    if (n % 2 == 0) {
        cout << n << ' ' << n << '\n';
    }
}