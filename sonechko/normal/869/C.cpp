#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const ll MOD = 998244353;
#define mod %MOD
const int N = 5000 + 11;
ll fac[N],st1[N],st2[N],st3[N];
ll step(ll k, ll r)
{
    if (r==0) return 1;
    if (r%2==1) return (k*step(k,r-1))mod;
    ll p=step(k,r/2);
    return (p*p)mod;
}
ll cc(ll k1, ll k2)
{
    ll res=fac[k1];
    res=(res*step(fac[k2],MOD-2))mod;
    res=(res*step(fac[k1-k2],MOD-2))mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    fac[0]=1;
    for (ll p=1; p<=5000; p++)
    fac[p]=(fac[p-1]*p)mod;
    for (int d=0; d<=a; d++)
    st1[d]=cc(a,d);
    for (int d=0; d<=b; d++)
    st2[d]=cc(b,d);
    for (int d=0; d<=c; d++)
    st3[d]=cc(c,d);
    ll ans=1;
    ll res=0;
    for (int d=0; d<=min(a,b); d++)
        res=(res+((st1[d]*st2[d])mod)*fac[d])mod;
    ans=res;
    res=0;
    for (int d=0; d<=min(b,c); d++)
        res=(res+((st2[d]*st3[d])mod)*fac[d])mod;
    ans=(ans*res)mod;
    res=0;
    for (int d=0; d<=min(a,c); d++)
        res=(res+((st1[d]*st3[d])mod)*fac[d])mod;
    ans=(ans*res)mod;
    cout<<ans<<endl;
}