#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        int sum = 0;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        for (int i = 0; i < n; i++) {
            int x = d[i];
            if (i == n - 1) {
                ans += x;
            }
            ans += sum - x * i;
            sum += x;
        }
        cout << ans << '\n';
    }
}