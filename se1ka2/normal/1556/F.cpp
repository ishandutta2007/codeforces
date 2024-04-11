#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res = res * r % MOD;
        r = r * r % MOD;
        n >>= 1;
    }
    return res;
}

ll b[20000];
ll dp[20000];
ll d[20][20000];

int main()
{
    int n;
    cin >> n;
    ll a[20];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                b[i] = b[i ^ (1 << j)] + 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int s = 0; s < (1 << n); s++){
            d[i][s] = 1;
            for(int j = 0; j < n; j++){
                if((s >> j) & 1) d[i][s] = d[i][s] * a[i] % MOD * modpow(a[i] + a[j], MOD - 2) % MOD;
            }
        }
    }
    ll ans = 0;
    for(int s = 1; s < (1 << n); s++){
        dp[s] = 1;
        for(int i = 0; i < n; i++){
            if((s >> i) & 1) dp[s] = dp[s] * d[i][((1 << n) - 1) ^ s] % MOD;
        }
        for(int t = (s - 1) & s;; t = (t - 1) & s){
            ll r = dp[t];
            for(int i = 0; i < n; i++){
                if(((s >> i) & 1) && !((t >> i) & 1)){
                    r = r * d[i][((1 << n) - 1) ^ s] % MOD;
                }
            }
            dp[s] = (dp[s] + MOD - r) % MOD;
            if(t == 0) break;
        }
        ans = (ans + dp[s] * b[s]) % MOD;
    }
    cout << ans << endl;
}