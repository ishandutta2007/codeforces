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
        string s;
        cin >> s;
        if (s.back() == 'A') {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int b = 0;
        for (int i = 0; i < s.size(); i++) {
            b += s[i] == 'A' ? 1 : -1;
            if (b < 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}