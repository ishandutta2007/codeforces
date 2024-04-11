#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

const int MOD = 31607;
const int N = 21;
const int STATES = (1 << 21) + 4;
const int T = 10000;

int n, inv;
int a[N][N], s[N][STATES], sz[STATES];
int dp[STATES];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    inv = 1;
    for(int i = 1; i <= MOD - 2; ++i)
        inv = inv * 10000 % MOD;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            s[i][1 << j] = a[i][j] * inv % MOD;
        }
        s[i][0] = 1;
        for(int j = 1; j < 1 << n; ++j)
            s[i][j] = s[i][j&-j] * s[i][j^j&-j] % MOD;
        for(int j = 0; j < 1 << n; ++j)
            s[i][j] -= s[i][(1 << n) - 1];
    }
    for(int i = 1; i < 1 << n; ++i)
        sz[i] = 1 + sz[i^i&-i];

    int ans = 1;
    for(int d = 0; d < 4; ++d){
        for(int i = 0; i < 1 << n; ++i)
            dp[i] = ((sz[i] + sz[d]) & 1) ? 1 : -1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 1 << n; ++j)
                dp[j] = dp[j] * s[i][j | (d & 1) << i | ((d >> 1) & 1) << (n - 1 - i)] % MOD;
        for(int i = 0; i < 1 << n; ++i){
            ans += dp[i];
            if(ans < 0) ans += MOD;
            else if(ans >= MOD) ans -= MOD;
        }
    }

    cout << ans << "\n";
}