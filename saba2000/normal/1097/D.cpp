#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll F[10009][59];
ll P[1009];
ll inv[100009];
main(){
    ll n , k;
    cin >> n >> k;
    ll N = n;
    vector<pair<ll,ll> > v;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            ll k = 0;
            while(n % i == 0) n/= i, k++;
            v.push_back({i, k});
        }
    }
    if(n > 1) v.push_back({n, 1});
    
    inv[0] = 1; inv[1] = 1;
    for(ll i = 2; i <= 100+1; i++)
        inv[i] = inv[mod % i] * (mod  - mod / i) % mod;
    ll ans = 1;
    for(ll i = 0; i < v.size(); i++){
        P[0] = 1;
        ll l = v[i].second;
        for(ll j = 1; j <= v[i].second; j++){
            P[j] = P[j - 1] * v[i].first;
            F[0][j] = 0;
        }
        F[0][0] = 0;
        F[0][l] = 1;
        for(ll i = 1; i <= k; i++)
            for(ll j = 0; j <= l; j++)
                F[i][j] = 0;
        for(ll  i = 1; i <= k; i++){
            for(ll j = 0; j <= l; j++)
                for(ll t = 0; t <= j; t++)
                    F[i][t] = (F[i][t] + F[i - 1][j] * inv[j + 1]) % mod;
        }
        ll S = 0;
        for(ll j = 0; j <= v[i].second; j++){
             S = (S + P[j] % mod * F[k][j]) % mod;
        }
        ans = ans * S % mod;
    }
    cout << ans << endl;
    
}