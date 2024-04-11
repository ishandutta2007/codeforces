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
    vector<int> ps;
    for (int i = 3; i < 50000; i += 2) {
        bool ok = true;
        for (int j : ps) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ps.push_back(i);
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "2\n";
            continue;
        }
        int k = 2;
        while (n % k == 0) {
            k *= 2;
        }
        int n_odd = n / (k / 2);
        if (k + 1 <= n_odd) {
            cout << k << '\n';
            continue;
        }
        int32_t n_odd32 = n_odd;
        if (n_odd == 1) {
            cout << "-1\n";
            continue;
        }
        int min_p = -1;
        for (int32_t p: ps) {
            if (p * p > n_odd32) {
                break;
            }
            if (n_odd32 % p == 0) {
                min_p = p;
                break;
            }
        }
        if (min_p == -1) {
            min_p = n_odd;
        }
        if (min_p * (min_p + 1) / 2 <= n) {
            cout << min_p << "\n";;
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}