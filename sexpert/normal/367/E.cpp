#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[350][350], fac[350], D[350][350];

int main() {
    fac[0] = 1;
    for(ll i = 1; i < 350; i++)
        fac[i] = (i * fac[i - 1])%MOD;
    int n, m, x;
    cin >> n >> m >> x;
    if(n > m) {
        cout << "0\n";
        return 0;
    }
    D[0][0]= dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int a = n; a >= 0; a--) {
            for(int b = n; b >= 0; b--) {
                if(i != x) {
                    ll to = 0;
                    if(a) {
                        to = (to + D[a - 1][b]) % MOD; // sz 1, autoclose
                        if(b)
                            to = (to + D[a - 1][b - 1]) % MOD;
                    }
                    to = (to + D[a][b]) % MOD;
                    to = (to + D[a][b + 1]) % MOD;
                    dp[a][b] = to;
                }
                else {
                    ll to = 0;
                    if(a) {
                        to = (to + D[a - 1][b]) % MOD;
                        if(b)
                            to = (to + D[a - 1][b - 1]) % MOD;
                    }
                    dp[a][b] = to;
                }
                //cout << "dp(" << i << ", " << a << ", " << b << ") = " << dp[a][b] << '\n';
            }
        }
        for(int a = 0; a <= n; a++)
            for(int b = 0; b <= n; b++)
                D[a][b] = dp[a][b];
    }
    ll tot = dp[n][0];
    cout << (tot*fac[n]) % MOD << '\n';
}