#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll fact[1000000];
ll inv[1000000];
ll Power(ll a,ll b) {
    if (b==0)return 1;
    ll x = Power(a,b/2);
    x = (x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
int main()
{
    ll D;
    int q;
    scanf("%lld%d",&D,&q);
    fact[0]=1;
    inv[0]=1;
    for (int i=1;i<=10000;i++){
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = Power(fact[i], mod-2);
    }
    vector<pair<ll,int> > vec;
    for (ll i=2;i*i<=D;i++){
        if (D%i==0) {
            int num=0;
            while (D % i == 0) {
                num++;
                D /= i;
            }
            vec.push_back({i,num});
        }
    }
    if (D!=1)vec.push_back({D,1});
    while(q--){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        vector<int> uv, vu;
        ll ret = 1;
        int sA=0,sB=0;
        for (auto [d,num]:vec){
            while(u%d==0 && v%d==0){
                u/=d,v/=d;
            }
            int a=0,b=0;
            while(u%d==0)u/=d,a++;
            while(v%d==0)v/=d,b++;
            sA+=a, sB+=b;
            ret = (ret*inv[a])%mod;
            ret = (ret*inv[b])%mod;
        }
        ret = (ret*fact[sA])%mod;
        ret = (ret*fact[sB])%mod;
        printf("%lld\n",ret);
    }
}