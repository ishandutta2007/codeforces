#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 5000 + 11;
const int MOD = 1e9 + 7;

int a[N],dp[5002][3002][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int m=(n+1)/2;
    for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
    for (int k=0; k<=1; k++)
        dp[i][j][k]=1e9;
    dp[0][0][0]=0;
    for (int i=1; i<=n; i++)
    for (int j=0; j<=m; j++)
    {
        dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+max(0,a[i]-(a[i-1]-1)));
        dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]);
        if (j>0)
        {
            dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][0]+max(0,a[i-1]-(a[i]-1)));
            if (i>=2) dp[i][j][1]=min(dp[i][j][1],
                        dp[i-2][j-1][1]+max(0,a[i-1]-(min(a[i],a[i-2])-1)));
        }
        ///cout<<i<<" "<<j<<" - "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
    }
    for (int i=1; i<=m; i++)
        cout<<min(dp[n][i][0],dp[n][i][1])<<" ";
    cout<<endl;
}