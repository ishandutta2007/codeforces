#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll dp[2005][2005];

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(int num = 2; num <= n; num++) {
        for(int diff = 0; diff <= k; diff++) {
            dp[num][diff] = (dp[num - 1][diff] + (m - 1)*(dp[num - 1][diff - 1]))%MOD;
        }
    }
    cout << dp[n][k] << endl;
}