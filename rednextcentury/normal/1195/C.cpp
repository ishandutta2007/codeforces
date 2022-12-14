#include<bits/stdc++.h>
using namespace std;
long long a[1000000][2];
long long dp[1000000][2];
    int n;
long long sol(int i,int last)
{
    if (i==n)return 0;
    if (dp[i][last]!=-1)return dp[i][last];
    return dp[i][last]=max(sol(i+1,last),sol(i+1,1-last)+a[i][1-last]);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i][0];
    for (int i=0;i<n;i++)
        cin>>a[i][1];
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        ret=max(ret,max(sol(i,0),sol(i,1)));
    }
    cout<<ret<<endl;
}