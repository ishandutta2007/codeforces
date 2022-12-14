#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[101][101][101];
int sol(int i,int j,int k)
{
    if (i<0 || j<0 || k<0)return -1e9;
    if (dp[i][j][k]!=-1)return dp[i][j][k];
    int ret=0;
    ret=max(ret,sol(i-1,j-2,k)+3);
    ret=max(ret,sol(i,j-1,k-2)+3);
    return dp[i][j][k]=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<sol(a,b,c)<<endl;
    }
}