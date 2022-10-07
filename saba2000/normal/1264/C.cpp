#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll inv[1009];
int f[200009];
ll mod = 998244353;
ll P[200009],IP[200009],S[200009];
ll F(int l, int r){
    return ((S[r-1] - S[l-1] + mod) * IP[l-1]+1) % mod * IP[r] % mod * P[l-1] % mod;
}
main(){
    ll n,q;
    cin >> n>>q;
    inv[1] =1;
    for(ll i = 2; i <=100; i++)
        inv[i] = inv[mod % i]*(mod-mod/i) % mod;
    ll I = inv[100];
    for(ll i = 1; i <= n; i++){
        int p;
        scanf("%d", &p);
        P[i] = inv[100] * p % mod;
        IP[i] = inv[p] * 100 % mod;
    }
    P[0] = 1;
    IP[0] = 1;
    for(int i = 1; i <= n; i++)
        P[i] = P[i-1] * P[i] % mod,
        IP[i] = IP[i-1] * IP[i] % mod;
    S[0] = 1;
    for(int i = 1; i <= n; i++)
        S[i] = (S[i-1] + P[i]) % mod;

    set<int> s;
    s.insert(1);
    s.insert(n+1);

    ll ans = F(1,n);
    while(q--){
        int u;
        scanf("%d", &u);
        if(f[u] == 0){
            auto it = s.lower_bound(u);
            int r = *it;
            it--; int l = *it;
            ans = (ans - F(l,r-1)+ mod) % mod;
            ans = (ans + F(l,u-1)) % mod;
            ans = (ans + F(u,r-1)) % mod;
            printf("%d\n",(int)ans);
            s.insert(u);
            f[u] = 1;
        }
        else{
            auto it = s.lower_bound(u+1);
            int r = *it;
            it--; it--; int l = *it;
            ans = (ans + F(l,r-1)) % mod;
            ans = (ans - F(l,u-1)+mod) % mod;
            ans = (ans - F(u,r-1)+mod) % mod;
            printf("%d\n",(int)ans);
            s.erase(s.find(u));
            f[u] = 0;
        }
    }

}