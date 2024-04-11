#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
int main()
{
    int n,m,c0,d0;
    cin>>n>>m>>c0>>d0;
    for (int i=c0;i<=n;i++) dp[i]=i/c0*d0;
    int a,b,c,d;
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b>>c>>d;
        for (int j=1;j<=a/b;j++)
        {
            for (int k=n;k>=c;k--)
            dp[k]=max(dp[k-c]+d,dp[k]);
        }
    }
    cout<<dp[n]<<endl;
}