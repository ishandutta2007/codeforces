#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll dp[3000009];
ll f[3000009],fi[3000009],inv[3000009];
ll c[3000009];
ll C(ll n, ll m){
    if(m < 0 || m > n || n < 0) return 0;
    return f[n] * fi[m] % mod* fi[n -m]% mod;
}
ll n, q;
main(){
    scanf("%lld %lld", &n, &q);
    dp[0] = n+1;
    dp[1] = 3*n*(n+1)/2 % mod;
    inv[1] = 1;
    f[0] = 1; fi[0] = 1;
    for(ll i = 1; i <= 3*n+3; i++){
        if(i > 1) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        f[i] = f[i-1] * i % mod;
        fi[i] = fi[i-1] * inv[i] % mod;
    }
     for(ll i = 0; i <= 3*n; i++){
         c[i] = C(3*n, i);
    }
    dp[2] = (9*n*(2*n+1)%mod*(n+1)%mod*inv[6]%mod-dp[1]+mod)*inv[2]%mod;
    for(ll i = 3; i <= 3*n; i++){
        dp[i]= ((3*(dp[i-1] - c[i-1]) +
                5*(dp[i-2] - c[i-2]) +
                2*(dp[i-3] - c[i-3]) +
                C(3*n+1, i+1)) % mod + mod)* inv[3] % mod;
    }

    while(q--){
        int k;
        scanf("%d", &k);
        printf("%lld\n", dp[k]);
    }

}