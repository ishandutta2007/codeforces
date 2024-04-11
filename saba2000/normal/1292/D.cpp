#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll g[5009],f[5009],p[5009];
ll h[5009][1009];
ll no[5009];
ll wp[5009];
ll F[5009];
main(){
    ll n;
    cin >> n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(ll i = 1; i <= n; i++){
        int k;
        scanf("%d",&k);
        if(k == 0) k = 1;
        f[k]++;
    }
    ll c= 0;
    for(ll i = 2; i <= 5000; i++){
        for(ll j = i; j <= 5000; j+=i)
            if(!p[j]) p[j] = i;
        if(p[i] == i) no[i] = ++c;//cout<<no[i]<<endl;
    }
    ll S=  0;
 
    for(ll i = 1; i <= 5000; i++){
        ll x = i,t = 0;
        while(x > 1)
            h[i][no[p[x]]]++, x /= p[x],t++;
        if(p[i] == i) wp[i] = no[i];
        else wp[i] = wp[i-1];
        F[wp[i]] += f[i];
        g[i] = g[i-1] +t;
        S += g[i] * f[i];
        for(ll j = 1; j <= c; j++)
            h[i][j] += h[i-1][j];
 
    }
    ll l = 1, r = 5000;
    ll u = 1;
    while(1){
 
        ll fl = 0;
        for(ll j = 1; j <= c; j++)
            if(2*F[j] >= n){
                S += n - 2*F[j];
                for(ll j = 1; j <= c; j++)
                    F[j] = 0;
                ll L = 1e9, R = 0;
                for(ll k = l; k <= r; k++){
                    if(wp[k] == j){
                        L = min(L, k);
                        R = max(R, k);
                        h[k][j] --;
                        if(h[k][j] == 0) wp[k] --;
                        F[wp[k]] += f[k];
                    }
                }
                l = L, r = R;
                fl = 1;
                break;
            }
        if(!fl) break;
    }
    cout << S << endl;
 
}