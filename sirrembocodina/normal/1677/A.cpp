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

short suf[5010][5010];
short pref[5010][5010];

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                pref[i][j] = suf[i][j] = 0;
            }
        }
        forn (i, n) {
            for (int j = 0; j < n; j++) {
                pref[i][j + 1] = pref[i][j] + (a[j] < i);
            }
            for (int j = n - 1; j >= 0; j--) {
                suf[i][j] = suf[i][j + 1] + (a[j] < i);
            }
        }
        int ans = 0;
        for (int i = 2; i < n - 1; i++) {
            for (int j = 1; j < i; j++) {
                ans += pref[a[i]][j] * 1ll * suf[a[j]][i + 1];
            }
        }
        cout << ans << '\n';
    }
}