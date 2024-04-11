#include<bits/stdc++.h>
using namespace std;

const int N = 5000 + 11;

int dp[N][N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        dp[1][i]=a[i];
    }
    for (int i=2; i<=n; i++)
    for (int j=1; j<=n-i+1; j++)
        dp[i][j]=(dp[i-1][j]^dp[i-1][j+1]);
    for (int i=2; i<=n; i++)
    for (int j=1; j<=n-i+1; j++)
        dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i-1][j+1]});
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp[r-l+1][l]<<"\n";
    }
}