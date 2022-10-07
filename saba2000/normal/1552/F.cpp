#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[200009],y[200009];
ll t[200009],s[200009],st[200009];
ll mod = 998244353;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> x[i] >> y[i] >> st[i];
    }
    t[1] = x[1] - y[1];
    ll ans = 0;
    s[1] = t[1];
    if(st[1]) ans = t[1];
    for(ll i = 2; i <= n; i++){
        ll ind = lower_bound(x, x + n, y[i]) - x;
        t[i] = ((x[ind] - y[i] +
               s[i-1] - s[ind - 1] +
               x[i] - x[ind])% mod + mod)%mod;
        s[i] = (s[i-1] + t[i]) % mod;
        if(st[i] == 1) ans = (ans + t[i])%mod;
    }
    cout <<( x[n] + 1 + ans)% mod<< endl;

}