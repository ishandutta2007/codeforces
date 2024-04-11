#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 100 + 11;
const int MOD = 1e9 + 7;

ll dp[N][N*N];
int fac[N];
ll kol[N];
ll cc[N][N];

int step(int x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (step(x,y-1)*1ll*x)mod;
    int c=step(x,y/2);
    return (c*1ll*c)mod;
}

int c(int n, int k)
{
    return cc[n][k];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[0][0]=1;
    int n;
    ll m;
    int k;
    cin>>n>>m>>k;
    cc[0][0]=1;
    for (int i=1; i<=n; i++)
    for (int j=0; j<=n; j++)
    cc[i][j]=(cc[i-1][j]+cc[i-1][j-1])mod;

    for (int i=1; i<=n; i++)
    {
        kol[i]=m/n;
        if (m%n>=i) kol[i]++;
    }
    for (int i=1; i<=n; i++)
    for (int p=0; p<=n; p++)
    {
        ll pp=step(c(n,p),kol[i]);
        for (int j=0; j<=k; j++)
    {
        dp[i][j+p]+=dp[i-1][j]*pp;
        dp[i][j+p]%=MOD;
    }
    }
    cout<<dp[n][k]<<endl;
}