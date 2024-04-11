#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353 ;
ll f[109],fi[109], inv[109];
ll A[109];
main(){
    ll D;
    f[0] = 1; f[1] = 1;
    inv[0]= 1;inv[1]=  1;
    for(int i =2 ; i<= 100; i++){
        f[i]  =f[i-1]*i % mod;
        inv[i] = inv[mod % i] * (mod - mod/  i) % mod;
    }
    fi[0] = 1;
    for(int i=1; i <= 100 ;i++)
        fi[i] = fi[i-1] * inv[i] % mod;
    cin >> D;
    vector<ll> P;
    for(ll i = 2; i * i<= D; i++){
        if(D % i == 0){
            P.push_back(i);
            while(D%i==0) D/=i;
        }
    }
    if(D > 1) P.push_back(D);
    int q;
    cin >>q;
    while(q--){
        ll u, v;

        scanf("%lld %lld", &u, &v);
        ll S1 =0,S2=0;
        vector<ll> A;
        for(int i = 0; i < P.size(); i++){
            ll p = P[i];
            ll U = 0, V= 0;
            while(u % p == 0) u/=p, U++;
            while(v % p == 0) v/=p, V++;
            if(U > V) S1 += U - V;
            else S2 += V- U;
            A.push_back(abs(U-V));
        }
        ll ans = f[S1] * f[S2] % mod;
        for(ll x : A)
            ans = ans * fi[x] % mod;
        printf("%lld\n", ans);
    }
}