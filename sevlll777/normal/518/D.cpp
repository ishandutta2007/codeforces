#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define int long long
long double dp[2020][2020];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    long double p;
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int time = 1; time <= t; time++) {
        for (int pipl = 0; pipl <= time; pipl++) {
            if (pipl == 0) {
                dp[pipl][time] = (1 - p) * dp[pipl][time - 1];
            } else {
                dp[pipl][time] = p * dp[pipl - 1][time - 1] + (1 - p) * dp[pipl][time - 1];
            }
        }
    }
    long double ans = 0;
    for (int z = 1; z <= n; z++) {
        long double sus = 0;
        for (int time = 0; time <= t-1; time++) sus += p * dp[z-1][time];
        ans += sus;
    }
    cout << fixed;
    cout << setprecision(9) << ans;


}