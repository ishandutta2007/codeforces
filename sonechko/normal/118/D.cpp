#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e2 + 11;
const int MOD=1e8;
#define mod %MOD
ll dp[N][N][20][2];
int main()
{
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    for (int i=1; i<=k1; i++)
    dp[i][0][i][1]=1;
    for (int i=1; i<=k2; i++)
    dp[0][i][i][2]=1;
    ll ans=0;
    for (int i=0; i<=n1; i++)
    for (int j=0; j<=n2; j++)
    {
            for (int t=1; t<=k1; t++)
                for (int p=1; p<=k2; p++)
                    if (i-t>=0)
            dp[i][j][t][1]=(dp[i][j][t][1]+dp[i-t][j][p][2])mod;

            for (int t=1; t<=k1; t++)
                for (int p=1; p<=k2; p++)
                if (j-p>=0)
            dp[i][j][p][2]=(dp[i][j][p][2]+dp[i][j-p][t][1])mod;

    }
    for (int t=1; t<=k1; t++)
    ans+=dp[n1][n2][t][1];
    for (int t=1; t<=k2; t++)
    ans+=dp[n1][n2][t][2];
    cout<<ans%MOD<<endl;
}