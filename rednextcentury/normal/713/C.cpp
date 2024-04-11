#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[3004];
int b[3004];
ll dp[3004][3004];
ll cost[3004][3004];
int n;
ll getCost(int i,int l,int r)
{
    if (l>r)return 1e15;
    return cost[i][r]-cost[i][l-1];
}
void solve(int i,int l,int r,int s,int e)
{
    if (l>r)return;
    int mid=(l+r)/2;
    int opt=s;
    dp[i][mid]=dp[i-1][mid];
    for (int x=s;x<=e;x++)
    {
        if (dp[i-1][x-1]+getCost(i,x,mid)<dp[i][mid])
        {
            dp[i][mid]=dp[i-1][x-1]+getCost(i,x,mid);
            opt=x;
        }
    }
    solve(i,l,mid-1,s,opt);
    solve(i,mid+1,r,opt,e);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],a[i]-=i,b[i]=a[i];
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cost[i][j]=cost[i][j-1]+((a[j]>b[i])?(a[j]-b[i]):(b[i]-a[j]));
    dp[0][0]=0;
    for (int i=1;i<=n;i++)dp[0][i]=1e15;
    for (int i=1;i<=n;i++)
        solve(i,1,n,0,n);
    ll ret=1e15;
    for (int i=1;i<=n;i++)
        ret=min(ret,dp[i][n]);
    cout<<ret<<endl;
}