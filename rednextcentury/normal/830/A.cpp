#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5000];
int b[5000];
ll dp[2020][2020];
ll p;
int n,m;
ll solve(int i,int j){
    if (i==n)return 0;
    if (j==m)return 1e18;
    if (dp[i][j]!=-1)return dp[i][j];
    ll ret = min(solve(i,j+1), max(solve(i+1,j+1),llabs(a[i]-b[j])+llabs(b[j]-p)));
    return dp[i][j]=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>p;
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n); sort(b,b+m);
    cout<<solve(0,0)<<endl;
}