#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[2][2];
ll x[6009],y[6009];
main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n ; i++){
        cin >> x[i] >> y[i];
        x[i] /= 2; y[i] /= 2;
        f[x[i]%2][y[i]%2] ++;
    }
    ll ans = 0 ;
    for(ll i = 0; i < (1<<6); i++){
        ll x[3],y[3];
        for(ll j = 0; j < 3; j++){
            x[j] = 0, y[j] = 0;
            if((1<<j)&i)x[j]= 1;
            if((1<<(j+3)&i)) y[j]=1;
        }
        ll p = __gcd(x[1]-x[2],y[1]-y[2])+
                __gcd(x[1]-x[0],y[1]-y[0])+
                __gcd(x[0]-x[2],y[0]-y[2]);
        if(p % 2) continue;
        ll A = f[x[0]][y[0]], B = f[x[1]][y[1]], C = f[x[2]][y[2]], fl =0;
        pair<ll,ll> a = {x[0], y[0]}, b = {x[1], y[1]}, c = {x[2], y[2]};
        ll S = A;
        if(a == b)
            S = S * (B - 1);
        else  S= S * B;
        if(a == b && b == c)
            S = S * (C - 2) ;
        else if(c == a || c == b) S = S * (C - 1);
        else S = S * C;
        ans += S;
    }
    cout<<ans/6<<endl;
}