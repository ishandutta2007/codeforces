#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int M[4][4] = {{0,1,1,1},
               {0,0,2,0},
               {0,2,0,0},
               {1,1,1,0}};
int P[4]={1,2,2,1};
int n,k;
long long dp[1001][2001][4];
long long sol(int i,int j,int mask)
{
    if (i==n) return j==k;
    if (j>k)return 0;
    if (dp[i][j][mask]!=-1)
        return dp[i][j][mask];
    long long ret=0;
    for (int m=0;m<4;m++)
    {
        ret+=sol(i+1,j+M[mask][m],m);
        ret%=998244353;
    }
    return dp[i][j][mask]=ret;
}
int main()
{
    fast;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    long long ret=0;
    for (int i=0;i<4;i++)
    {
        ret+=sol(1,P[i],i);
        ret%=998244353;
    }
    cout<<ret<<endl;
}