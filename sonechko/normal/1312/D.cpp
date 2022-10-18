#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 998244353;

ll fac[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*1ll*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*1ll*p)%MOD;
}

ll cnk(int n, int k)
{
    ll p=fac[n];
    p=(p*1ll*step(fac[k],MOD-2))%MOD;
    p=(p*1ll*step(fac[n-k],MOD-2))%MOD;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    if (n==2)
    {
        cout<<0;
        return 0;
    }
    fac[0]=1;
    for (int i=1; i<=m; i++)
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    ll ans=0;
    for (int i=1; i<m; i++)
    {
        ll c=cnk(m-1,n-2);
        if (i-1>=n-2) c-=cnk(i-1,n-2);
        ans=(ans+c+MOD)%MOD;
    }
    n-=2;
    ll p=(step(2,n-1))%MOD;
    ///cout<<"! "<<p<<endl;
    ans=(ans*1ll*p)%MOD;
    cout<<ans;
}
/**

**/