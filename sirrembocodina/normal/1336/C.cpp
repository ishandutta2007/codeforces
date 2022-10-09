
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define sqr(x) (x) * (x)

using namespace std;

const int mod = 998244353;

int dp[3010][3010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 3010; i++) {
        if (i >= t.size() || t[i] == s[0]) {
            dp[i][1] = 1;
        }
    }
    for (int len = 1; len < s.size(); len++) {
        for (int i = 0; i < 3010; i++) {
            if (i > 0 && (i - 1 >= t.size() || t[i - 1] == s[len])) {
                dp[i - 1][len + 1] += dp[i][len];
                dp[i - 1][len + 1] %= mod;
            }
            if (i + len >= t.size() || t[i + len] == s[len]) {
                dp[i][len + 1] += dp[i][len];
                dp[i][len + 1] %= mod;
            }
        }
    }
    /*for (int len = 1; len <= 4; ++len) {
        for (int i = 0; i < 4; i++) {
            cerr << dp[i][len] << " ";
        }
        cerr << endl;
    }*/
    int ans = 0;
    for (int i = t.size(); i <= s.size(); i++) {
        ans += dp[0][i];
        ans %= mod;
    }
    cout << ans * 2 % mod << endl;
}