#include<bits/stdc++.h>
#define ll long long
using namespace std;
exp (ll a, ll b, ll mod){
    if(b==0) return 1;
    if(b&1) return a*exp(a,b-1,mod)%mod;
    return exp(a*a%mod, b/2, mod);
}
ll mod = 1e9+9;
main(){
    ll n, a,b,k;
    cin >>n >> a >> b >> k;
    string s;
    ll inva = exp(a,mod-2,mod);
    ll Co = exp(a, n,mod);
    b = (b*inva) % mod;
    cin >> s;
    ll T = (n+1)/k;
    ll ans = 0;
    ll ANS = 0;
    for (ll i= 0; i < k; i++){
        if(s[i] == '+')
            ans = (ans + exp(b, i,mod))%mod;
            else ans = (ans -exp(b,i,mod) + mod)%mod;
    }
    ll P = exp(b, k,mod);
    ll G;
   if(P == 1) G = T; else
    if(P==0) G = 0; else
    G = ((exp( P, T,mod)-1+mod)%mod)*exp((P-1+mod)%mod, mod-2, mod)%mod;

   if(G < 0) G +=mod;
   if(ans <0)ans+=mod;
   cout<<(ans*G%mod)*Co%mod<<endl;
}