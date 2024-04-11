#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int MOD = 998244353;
const int N = 1e6 + 11;

pair<int,pair<ll,ll> > a[N];
ll s1[N],s2[N],s3[N],s4[N];
ll d[N],t[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*1ll*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*p)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        int l;
        cin>>l;
        a[(i-1)*m+j]=mp(l,mp(i,j));
    }
    n*=m;
    int l,r;
    cin>>l>>r;
    sort(a+1,a+n+1);
    ll pos=0;
    for (int i=1; i<=n; i++)
    {
        s1[i]=(s1[i-1]+2*a[i].ss.ff)%MOD;
        s2[i]=(s2[i-1]+a[i].ss.ff*a[i].ss.ff)%MOD;
        s3[i]=(s3[i-1]+2*a[i].ss.ss)%MOD;
        s4[i]=(s4[i-1]+a[i].ss.ss*a[i].ss.ss)%MOD;
        if (a[i].ss.ff==l&&a[i].ss.ss==r) pos=i;
    }
    d[pos]=1;
    n=pos;
    ll ans=0;
    for (int i=n; i>=1; i--)
    {
        while (pos>0&&a[i].ff==a[pos].ff)
            pos--;
        if (pos==0) break;
        ll p=(d[i]+t[i])%MOD;
        t[i-1]=(t[i-1]+t[i])%MOD;
        ll c=(p*step(pos,MOD-2))%MOD;
        t[pos]=(t[pos]+c)%MOD;

        ll s=(s2[pos]
              -(s1[pos]*a[i].ss.ff)%MOD
              +((a[i].ss.ff*a[i].ss.ff)%MOD)*pos
              +MOD)%MOD;

        s=(s+s4[pos]
              -(s3[pos]*a[i].ss.ss)%MOD
              +((a[i].ss.ss*a[i].ss.ss)%MOD)*1ll*pos
              +MOD)%MOD;

        ans=(ans+c*1ll*s)%MOD;
    }
    cout<<ans<<endl;
}