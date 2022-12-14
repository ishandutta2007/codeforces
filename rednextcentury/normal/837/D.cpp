#include<bits/stdc++.h>
using namespace std;
pair<int,int> get(long long x)
{
    int a=0;
    int b=0;
    while(x%5==0)
        x/=5,a++;
    while(x%2==0)
        x/=2,b++;
    return make_pair(a,b);
}
int dp[2][203][27*202];
pair<int,int> a[201];
int m[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        a[i]=get(x);
        m[i]=a[i].first;
        if (i>0)
            m[i]+=m[i-1];
    }
    bool p=0;
    for (int i=0;i<=k;i++)
        for (int j=0;j<=m[0];j++)
            dp[0][i][j]=-1000000;
    dp[0][0][0]=0;
    dp[0][1][a[0].first]=a[0].second;
    int mx=0;
    for (int i=1;i<n;i++)
    {
        for (int x=0;x<=m[i-1];x++)
            mx = max(mx,min(x,dp[p][k][x]));
        for (int j=0;j<=k;j++)
            for (int x=0;x<=m[i];x++)
                dp[!p][j][x]=-1000000;
        for (int j=0;j<=k;j++)
        {
            for (int x=0;x<=m[i-1];x++)
            {
                dp[!p][j][x]=max(dp[!p][j][x],dp[p][j][x]);
                dp[!p][j+1][x+a[i].first]=max(dp[p][j][x]+a[i].second,dp[!p][j+1][x+a[i].first]);
            }
        }
        p=!p;

    }
    for (int x=0;x<=m[n-1];x++)
        mx = max(mx,min(x,dp[p][k][x]));
    cout<<mx<<endl;
}