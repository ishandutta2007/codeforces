#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 14 + 3;
const int N2 = (1 << 14) + 3;
const int N3 = 4782969 + 3;
const int MOD = 1e9+7;
const int X = 2e6;

int a[N], n, dp[N2], d, inv[N][N], ans = 0;

int fast_pow(int base, int exp){
    if(!exp) return 1;
    if(exp & 1) return (ll)base * fast_pow(base, exp - 1) % MOD;
    int t = fast_pow(base, exp >> 1);
    return (ll)t * t % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            inv[i][j] = fast_pow(a[i] + a[j], MOD - 2);

    d = 1;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            d = (ll)d * (a[i] + a[j]) % MOD;
    d = fast_pow(d, MOD - 2);

    for(int mask = 1; mask < (1 << n); ++mask){
        dp[mask] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j){
                int bit_i = ((mask >> i) & 1); 
                int bit_j = ((mask >> j) & 1);
                if(bit_i != bit_j){
                    if(bit_i) dp[mask] = (ll)dp[mask] * a[i] % MOD;
                    else dp[mask] = (ll)dp[mask] * a[j] % MOD;
                }
                else dp[mask] = (ll)dp[mask] * (a[i] + a[j]) % MOD;
            }

        for(int s = mask; s; s = (s - 1) & mask){
            if(s == mask) continue;
            int excl = mask ^ s;
            int oth = ((1 << n) - 1) ^ mask;
            int x = 1;
            for(int i = 0; i < n; ++i){
                if(!((1 << i) & excl)) continue;
                for(int j = 0; j < n; ++j){
                    if(!((1 << j) & oth)) continue;
                    x = (ll)x * a[i] % MOD * inv[i][j] % MOD;
                }
            }
            dp[mask] = (dp[mask] - (ll)x * dp[s]) % MOD;
            if(dp[mask] < 0) dp[mask] += MOD;
        }
        ans = (ans + __builtin_popcount(mask) * (ll)dp[mask]) % MOD;
        //cout << dp[mask] << " dp[" << mask << "]\n"; 
    }
    ans = (ll)ans * d % MOD;
    ans %= MOD;

    cout << ans << "\n";
}