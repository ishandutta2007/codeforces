#include <bits/stdc++.h>
using namespace std;
int a[5001];
int dp[5001][5001];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1;
    for (int r=1;r<=n;r++)
    {
        while(a[r]-a[l]>5)l++;
        for (int i=1;i<=k;i++)
            dp[i][r]=max(dp[i][r-1],dp[i-1][l-1]+(r-l+1));
    }
    cout<<dp[k][n]<<endl;
}