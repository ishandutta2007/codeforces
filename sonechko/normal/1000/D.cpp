#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod %MOD

const int N = 1e5 + 11;
const int MOD = 998244353;

ll dp[N],fac[N],unfac[N],a[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*step(x,y-1))mod;
    ll p=step(x,y/2);
    return (p*p)mod;
}

ll c(ll x, ll y)
{
    return (((fac[x]*unfac[y])mod)*unfac[x-y])mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    fac[0]=1;
    for (int i=1; i<=n; i++)
        fac[i]=(fac[i-1]*1ll*i)mod;
    unfac[n]=step(fac[n],MOD-2);
    for (int i=n-1; i>=0; i--)
        unfac[i]=(unfac[i+1]*1ll*(i+1))mod;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    dp[n+1]=1;
    ll ans=0;
    for (int i=n; i>=1; i--)
        if (a[i]>0)
    {
        for (int j=i+1; j<=n+1; j++)
            if (j-i-1>=a[i]) dp[i]=(dp[i]+dp[j]*c(j-i-1,a[i]))mod;
        ans=(ans+dp[i])mod;
    }
    cout<<ans<<endl;
}