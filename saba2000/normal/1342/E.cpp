#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[400009],fi[400009],inv[400009];
ll mod =  998244353;
ll dp[400009];
ll C(ll n, ll m){
    if(n < m || m < 0) return 0;
    return f[n] * fi[m] % mod * fi[n-m]% mod;
}
ll exp(ll a, ll b){
    if(!b) return 1;
    if(b&1) return a*exp(a*a%mod, (b-1)/2) %mod;
    return exp(a*a%mod, b/2);
}
main(){
    ll n, k;
    cin >> n >> k;
    inv[1] = 1;
    f[0] = 1;
    for(ll i = 1; i <= 2*n; i++){
        f[i] = f[i-1] * i % mod;

    }
    for(ll i = 2; i <= 2*n; i++)
        inv[i]  = inv[mod%i]*(mod- mod/i) % mod;
    fi[0] = 1;
    for(ll i=1; i <= 2*n; i++){
        fi[i] = fi[i-1] * inv[i] % mod;
    }
    if(k >= n){
        cout<<0<<endl;
        return 0;
    }
    if(!k){
        cout<<f[n]<<endl;
        return 0;
    }
    ll ans = 0;
    ll x = n - k;
    for(ll i = 0; i <= x; i++){
        ll sg = 1;
        if((x - i) % 2) sg = -1;
        ans = (ans + sg * C(x,i) * exp(i, n)% mod + mod)% mod;
    }

    cout <<2* ans * C(n,x) %mod<< endl;

}