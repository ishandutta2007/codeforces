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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int sum_a0 = 0;
        for (int i = 1; i < n; i++) {
            sum_a0 += a[0] + a[i];
        }
        int sum_ab = 0;
        for (int i = 0; i < n - 1; i++) {
            sum_ab += a[i] + a.back();
        }
        if (sum_a0 > 0 || sum_ab < 0) {
            cout << "INF\n";
            continue;
        }
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + a[i];
        }
        int ans = -2e18;
        for (int i = 0; i < n; i++) {
            int cur = -a[i] * a[i] * (n - 1);
            cur += (sum[n] - sum[i + 1] - a[i] * (n - i - 1)) * (a[0] - a[i]);
            cur += (sum[i] - sum[1] - a[i] * (i - 1)) * (a[n - 1] - a[i]);
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}