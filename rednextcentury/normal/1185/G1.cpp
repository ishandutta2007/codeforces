#include <bits/stdc++.h>
using namespace std;
long long dp[1<<15][225][3];
int t[100];
int g[100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,T;
    cin>>n>>T;
    for (int i=0; i<n; i++)
    {
        cin>>t[i]>>g[i];
        g[i]--;
        dp[(1<<i)][t[i]][g[i]]=1;
    }
    int mx = (1<<15);
    for (int i=0; i<mx; i++)
    {
        for (int c=0; c<n; c++)
        {
            if (!(i&(1<<c)))continue;
            for (int j=t[c]; j<=T; j++)
            {
                for (int px=0; px<3; px++)
                {
                    if (g[c]==px)continue;
                    dp[i][j][g[c]]+=dp[i-(1<<c)][j-t[c]][px];
                    dp[i][j][g[c]]%=1000000007;
                }
            }
        }
    }
    long long ret=0;
    for (int i=0;i<mx;i++) {
        for (int j=0;j<3;j++) {
            ret = ret + dp[i][T][j];
            ret%=1000000007;
        }
    }
    cout<<ret<<endl;
}