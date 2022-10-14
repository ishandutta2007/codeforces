#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n; i++) {
            g[min(i + A[i], n)].pb(i);
        }
        vector<int> dp(n+1);
        int m= 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (auto x : g[i]) {
                dp[i] = max(dp[i], dp[x] + A[x]);
            }
            m = max(m, dp[i]);
        }
        cout << m;
        cout << '\n';
    }

}