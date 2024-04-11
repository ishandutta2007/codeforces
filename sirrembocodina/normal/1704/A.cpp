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

//int mod = 998244353;

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        int mn = 2e18, mx = -2e18;
        for (int i = 0; i < n - m + 1; i++) {
            mn = min(mn, int(s[i]));
            mx = max(mx, int(s[i]));
        }
        if (mn == mx && mn != t[0]) {
            cout << "NO\n";
            continue;
        }
        cout << (s.substr(n - m + 1) == t.substr(1) ? "YES\n" : "NO\n");
    }
}