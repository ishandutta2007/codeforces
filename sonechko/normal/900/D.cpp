#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define ld long double
const ll N = 1e6 + 11;
const ll mod = 1e9 + 7;
map<int,ll> mt;
ll pow_(ll x, ll p)
{
    if (p==0) return 1ll;
    if (p%2==1) return (pow_(x,p-1)*x)%mod;
    ll pp=pow_(x,p/2);
    return (pp*pp)%mod;
}
ll pp(ll k)
{
    if (k==1) return 1;
    if (mt[k]!=0) return mt[k];
    ll res=pow_(2,k-1);
    for (int j=2; j<=(int)sqrt(k); j++)
        if (k%j==0)
    {
        res=(res+mod-pp(k/j))%mod;
        if (k/j!=j) res=(res+mod-pp(j))%mod;
    }
    res--;
    mt[k]=res;
    return res;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y;
    cin>>x>>y;
    if (y%x!=0) {cout<<0<<endl; return 0;}
    y/=x;
    ll ans=pp(y);
    cout<<ans<<endl;
}