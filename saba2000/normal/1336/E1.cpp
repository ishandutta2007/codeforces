#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353;
bool f[10009];
ll g[10009][24];
ll a[200009];
ll ans[209];
main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    vector<ll> v;
    for(ll i = m-1; i >=0; i--){
        for(ll j = 1; j <= n; j++){
            if(a[j] & (1ll<<i)){
                v.push_back(a[j]);
                ll x = a[j];
                for(ll k = 1; k <= n; k++){
                    if(a[k] & (1ll<<i)) a[k] ^= x;
                }
                break;
            }
        }
    }
    ll X = 1;
    for(ll i = 0; i < n - v.size(); i++)
        X = X*2%mod;
    vector<ll> w, u;
    w.push_back(0);
    u.push_back(0);
    for(ll i = 0; i < v.size(); i++){
        if(v[i] >= (1ll << 12)){
            ll d =  w.size();
            for(ll j = 0 ;j <d; j++)
                w.push_back(v[i]^ w[j]);

        }
        else{
            ll d = u.size();
            for(ll j = 0; j < d; j++)
                u.push_back(v[i] ^ u[j]);
        }
    }
    for(ll i = 0; i < u.size(); i++){
        f[u[i]] = 1;
    }
    for(ll i = 0; i < w.size(); i++){
        ll x = w[i];
        ll y = (x>>12);
        g[x&((1ll<<12)-1)][__builtin_popcount(y)]++;
    }
    for(ll x = 0; x < (1ll<<12); x++){
        for(ll y = 0;  y < (1ll<<12); y++){
            for(ll z = 0; z <= max(0ll, m - 12); z++){
                if(f[y])
                {ans[z + __builtin_popcount(x^y)] += g[x][z];}
            }
        }
    }
    for(ll i = 0; i <= m; i++){
        cout << ans[i] % mod * X % mod<<" ";
    }

}