#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 11;
#define pb push_back

int dp[11][N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q,c;
    cin>>n>>q>>c;
    for (int i=1; i<=n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        dp[k][l][r]++;
    }
    n=100;
    for (int k=0; k<=10; k++)
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    dp[k][i][j]+=dp[k][i][j-1]+dp[k][i-1][j]-dp[k][i-1][j-1];
    for (int i=1; i<=q; i++)
    {
        int t,x1,y1,x2,y2,ans=0;
        cin>>t>>x1>>y1>>x2>>y2;
        for (int k=0; k<=c; k++)
        ans+=(dp[k][x2][y2]-dp[k][x1-1][y2]-dp[k][x2][y1-1]+dp[k][x1-1][y1-1])*((t+k)%(c+1));
        cout<<ans<<"\n";
    }
}