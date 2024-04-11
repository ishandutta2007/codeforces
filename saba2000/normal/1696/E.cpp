#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll f[500009];
ll fi[500009];
ll inv[500009];
ll a[500009];
ll mod = 1e9 + 7;
ll C(ll n, ll m){
    if(m < 0 || m > n) return 0;
    return f[n] * fi[m] % mod * fi[n-m]% mod;
}
main(){
    ll n;
    cin >> n;
    f[0] = 1;
    fi[0] = 1;
    inv[1] = 1;
    for(ll i = 1; i <= 4e5; i++){
        f[i] = f[i-1] * i % mod;
        if(i > 1) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        fi[i] = fi[i-1] * inv[i]% mod;
    }
    ll ans = 0;
    for(ll i = 1; i <= n+1; i++){
        cin >> a[i];
        ans = (ans +C(a[i] + i - 1, i))%mod;
    }
    cout<<ans<<endl;

}
/*
1
1 1

*/