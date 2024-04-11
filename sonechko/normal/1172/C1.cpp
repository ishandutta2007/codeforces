#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100 + 11;
const int MOD = 998244353;

ll a[N];
ll b[N],c[N];
ll dp[N][N][N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*p)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==0) a[i]=-1;
    }
    int s=0,s0=0,s1=0;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        c[i]=1;
        s+=b[i];
        if (a[i]==-1) s0+=b[i]; else s1+=b[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (a[i]==1) s1-=b[i]; else s0-=b[i];
        for (int j=0; j<=m; j++)
        for (int p=0; p<=m; p++)
        for (int k=0; k<=m; k++)
        dp[j][p][k]=0;
        dp[0][0][0]=1;
        for (int j=1; j<=m; j++)
        for (int p=0; p<j; p++)
        for (int t=0; t<j; t++)
            if (p+t<=j-1)
        {
            int g=b[i]+p*a[i];
            int sum=s + p*a[i] + t - (j-1-t-p);
            int sum1=s1 + t;
            int sum2=s0 - (j-1-t-p);
            if (g<0) continue;
            if (sum2<0) continue;
            /// if take this
            int d1=(g*1ll*step(sum,MOD-2))%MOD;
            int d2=(sum1*1ll*step(sum,MOD-2))%MOD;
            int d3=(sum2*1ll*step(sum,MOD-2))%MOD;
            dp[j][p+1][t]=(dp[j][p+1][t]*1ll+dp[j-1][p][t]*1ll*d1)%MOD;
            dp[j][p][t+1]=(dp[j][p][t+1]*1ll+dp[j-1][p][t]*1ll*d2)%MOD;
            dp[j][p][t]=(dp[j][p][t]*1ll+dp[j-1][p][t]*1ll*d3)%MOD;
        }
        ll ans=0;
        for (int j=0; j<=m; j++)
        {
            ll kol=0;
            for (int p=0; p<=m; p++)
                kol=(kol*1ll+dp[m][j][p])%MOD;
            if (b[i]+j*a[i]<0) continue;
            ///cout<<i<<": "<<b[i]+j*a[i]<<" = "<<kol<<endl;
            ans=(ans*1ll+kol*1ll*(b[i]+j*a[i]))%MOD;
        }
        if (a[i]==1) s1+=b[i]; else s0+=b[i];
        cout<<ans<<"\n";
    }
}