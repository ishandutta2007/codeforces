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
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 100) {
            cout << n % 10 << endl;
            continue;
        }
        int ans = 10;
        while (n) {
            ans = min(ans, n % 10);
            n /= 10;
        }
        cout << ans << endl;
    }
}
/*
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        */