#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;

#define mod %MOD

ll get(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (get(x,y-1)*1ll*x)mod;
    ll p=get(x,y/2);
    return (p*1ll*p)mod;
}

ll divv(ll a, ll b)
{
    if (a<0) a+=MOD;
    return (a*get(b,MOD-2))mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=1,p=0;
    if (n%2==1)
    {
        ans=k%MOD;
    }
    n/=2;
    vector<ll> v;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        if (i==m) p=n-l; else v.pb(n-l);
    }
    ans=(ans*get(k,p*2))mod;
    reverse(v.begin(),v.end());
    v.pb(n);
    //for (int i=0; i<v.size(); i++)
    //    cout<<v[i]<<" ";
    //cout<<endl;
    //cout<<"!!! "<<ans<<endl;
    for (int i=0; i<v.size(); i++)
    {
        ll l=v[i];
        ll kol_all=get(k,(l-p)*2);
        ll kol_pal=get(k,(l-p));
        //cout<<l-p<<" "<<kol_all<<" "<<kol_pal<<endl;
        p=l;
        ll kol=divv(kol_all-kol_pal,2ll)+kol_pal;
        ///ll kol=kol_pal;
        //cout<<" * "<<kol<<endl;
        ans=(ans*kol)mod;
    }
    cout<<ans<<endl;
}

/**
abc = cba
(kilkict usix - kilkist palind ) / 2 + kilkist palind


a ^ len
a ^ ((len+1)/2)
**/