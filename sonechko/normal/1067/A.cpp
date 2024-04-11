#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod %MOD

const int MOD = 998244353;
const int N = 1e5 + 11;

int dp[2][201][N];
int sum[2][201][N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    if (a[1]!=-1)
    {
        dp[0][a[1]][1]=1;
    } else
    {
        for (int i=1; i<=200; i++)
            dp[0][i][1]=1;
    }
    for (int i=1; i<=200; i++)
    {
        sum[0][i][1]=(dp[0][i][1]+sum[0][i-1][1])mod;
    }
    for (int i=2; i<=n; i++)
    {
        if (a[i]!=-1)
        {
            dp[0][a[i]][i]=(sum[0][a[i]-1][i-1]+sum[1][a[i]-1][i-1])mod;
            dp[1][a[i]][i]=(sum[1][200][i-1]-sum[1][a[i]][i-1]+MOD)mod;
            dp[1][a[i]][i]=(dp[1][a[i]][i]+dp[1][a[i]][i-1])mod;
            dp[1][a[i]][i]=(dp[1][a[i]][i]+dp[0][a[i]][i-1])mod;
        } else
        {
            for (int j=1; j<=200; j++)
            {
                dp[0][j][i]=(sum[0][j-1][i-1]+sum[1][j-1][i-1])mod;
                dp[1][j][i]=(sum[1][200][i-1]-sum[1][j][i-1]+MOD)mod;
                dp[1][j][i]=(dp[1][j][i]+dp[1][j][i-1])mod;
                dp[1][j][i]=(dp[1][j][i]+dp[0][j][i-1])mod;
                //cout<<"on pos "<<i<<" = "<<j<<" - "<<dp[0][j][i]<<" "<<dp[1][j][i]<<endl;
            }
        }
        for (int j=1; j<=200; j++)
        {
            sum[0][j][i]=(dp[0][j][i]+sum[0][j-1][i])mod;
            sum[1][j][i]=(dp[1][j][i]+sum[1][j-1][i])mod;
        }
    }
    int ans=0;
    for (int j=1; j<=200; j++)
        ans=(ans+dp[1][j][n])mod;
        cout<<ans<<endl;
}
/**

**/