#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[500009], N[100],F[100],M[100],P[100];
ll mod = 1e9 + 7;
main(){
    P[0] = 1;
    for(ll i = 1; i < 60; i++)
        P[i] = P[i-1] * 2 % mod;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin >> n;
         for(ll j = 0; j < 60; j++){
            N[j] = 0;
        }
        for(ll i = 1; i <= n; i++){
            cin >> x[i];
            for(ll j = 0; j < 60; j++){
                if((1ll<<j)&x[i]) N[j]++;
            }
        }
        ll sum = 0;
        for(ll i = 1; i <= n; i++){
            for(ll j = 0; j < 60; j++){
                if((1ll<<j)&x[i]) F[j] = 1; else F[j] = 0;
            }
            ll A = 0, B = 0;
            for(ll j = 0; j < 60; j++){
                if(F[j]) A += P[j]* N[j] % mod,
                        B += P[j] * n % mod;
                else B += P[j]* N[j] % mod;
            }
            sum += A% mod * (B % mod) % mod;
        }
        cout<<sum % mod << endl;


    }

}