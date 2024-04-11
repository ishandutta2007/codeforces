#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 50 + 11;

int n,mod;

int dp[N][N*N],d[N][N*N],mx[N];

int g[N];

int cnk(int n, int k)
{
    for (int i=1; i<=n; i++)
    {
        int t=i;
        for (int d=2; d<=n; d++)
        {
            while (t%d==0) {g[d]++; t/=d;}
        }
    }
    for (int i=1; i<=k; i++)
    {
        int t=i;
        for (int d=2; d<=n; d++)
        {
            while (t%d==0) {g[d]--; t/=d;}
        }
    }
    for (int i=1; i<=n-k; i++)
    {
        int t=i;
        for (int d=2; d<=n; d++)
        {
            while (t%d==0) {g[d]--; t/=d;}
        }
    }
    int ans=1;
    for (int i=1; i<=n; i++)
    {
        while (g[i]>0) {g[i]--; ans=(ans*1ll*i)%mod;}
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>mod;

    dp[1][0]=1;
    d[1][0]=1;
    mx[1]=0;
    for (int i=2; i<=n; i++)
    {
        for (int x=1; x<=i; x++)
        for (int t=0; t<=mx[i-1]; t++)
        {
            dp[i][t+x-1]=(dp[i][t+x-1]+dp[i-1][t])%mod;
        }
        mx[i]=mx[i-1]+i-1;
        for (int j=mx[i]; j>=0; j--)
            d[i][j]=(d[i][j+1]+dp[i][j])%mod;
    }
    int ans=0;
    for (int pos=1; pos<=n; pos++)
    {
        int c1 = cnk(n,pos-1);
        for (int g=1; g<pos; g++)
            c1=(c1*1ll*g)%mod;
        int k=n-pos+1;
        int res=0;
        for (int d1=1; d1<=k; d1++)
        for (int d2=d1+1; d2<=k; d2++)
        {
            int kol=0;
            for (int k2=0; k2<=mx[k-1]; k2++)
        {
            int s2=d2-1+ k2;
            int min_k1 = s2-d1+1;
            res=(res*1ll+d[k-1][min_k1+1]*1ll*dp[k-1][k2])%mod;
            kol=(kol*1ll+d[k-1][min_k1+1]*1ll*dp[k-1][k2])%mod;
        }
        }
        ans=(ans*1ll+c1*1ll*res)%mod;
    }
    cout<<ans;
}
/**
2725016
**/