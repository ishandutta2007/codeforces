#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

ll kol(ll x)
{
    if (x==1) return 0;
    ll kol_=0;
    while (1==1)
    {
        ll y=0;
        while (x>0)
        {
            if (x%2==1) y++;
            x/=2;
        }
        x=y;
        kol_++;
        if (x==1) return kol_;
    }
}

const ll mod = 1e9 + 7;

ll a[1010][1010];
ll fac[1010];

ll cnt(ll l, ll r)
{
    if (r>l) return 0;
    if (r==0) return 1;
    return a[l][r];
}

ll step(ll l, ll r)
{
    if (r==0) return 1;
    if (r%2==1) return (step(l,r-1)*l)%mod;
    ll p=step(l,r/2);
    return (p*p)%mod;
}

void up(ll n)
{
    fac[0]=1;
    for (ll i=1; i<=n; i++)
        fac[i]=(fac[i-1]*i)%mod;
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=i; j++)
        {
            a[i][j]=(fac[i]*step(fac[j],mod-2))%mod;
            a[i][j]=(a[i][j]*step(fac[i-j],mod-2))%mod;
        }
    }
}

ll g(string s, ll d)
{
    if (d>s.size()) return 0;
    ll kol=0;
    ll ks=0;
    for (ll j=0; j<s.size(); j++)
        if (s[j]=='1') kol++;
    if (kol==d) ks++;
    kol=0;
    for (ll i=0; i<s.size(); i++)
    {
        if (s[i]=='1') ks=(ks+cnt(s.size()-i-1,d-kol))%mod;
        if (s[i]=='1') kol++;
        if (kol>d) break;
    }
    return ks;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    ll k;
    up(s.size()+2);
    cin>>k;
    ll ans=0;
    if (k==0) {cout<<1<<endl; return 0;}
    for (ll i=1; i<=1000; i++)
    {
        if (kol(i)==k-1) ans=(ans+g(s,i))%mod;
    }
    if (k==1) cout<<ans-1<<endl; else cout<<ans<<endl;
}