#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4028;
const int MOD = 1e9 + 7;

ll ncr[MAXN][MAXN];
ll dp[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    ncr[0][0] = 1;
    for (int n = 1; n < MAXN; n++) {
        for (int r = 0; r <= n; r++) {
            ncr[n][r] = ncr[n-1][r];
            if(r) ncr[n][r] = (ncr[n][r] + ncr[n-1][r-1]) % MOD;
        }
    }        
        
    dp[0] = 1; 

    for (int i = 1; i < MAXN; i++) {
        for (int g = 2; g <= i; g++) {
            ll ch = ncr[i-1][g-1];
            dp[i] += ch * dp[i-g] % MOD;
            dp[i] %= MOD;
        }
    }

    int N; cin >> N;

    ll ans = 0;
    for (int s = 1; s <= N; s++) {
        ll w = ncr[N][s];
        w = w * dp[N-s] % MOD;

        ll m = 1;
        for (int i = 0; i < s; i++) m = 2 * m % MOD;
        m = (m + MOD - 1) % MOD;

        ans += m * w % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}