
 #include <bits/stdc++.h>

using namespace std;
int a[1000005];
int dp[1000001][7][7];
int n,m;
int sol(int i,int j,int k)
{
    if (j>4 || k>4)return 0;
    if (i==m+1)return 0;
    if (dp[i][j][k]!=-1)return dp[i][j][k];
    int &ret=dp[i][j][k];
    if (i+2>m)
        return sol(i+1,k,0)+(a[i]-j)/3;
    int pos = min(a[i]-j,min(a[i+1]-k,a[i+2]));
    for (int x=0;x<=pos;x++)
    {
        ret=max(ret,sol(i+1,k+x,x)+x+(a[i]-x-j)/3);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    int ret=0;
    for (int i=1;i<=m;i++)
    {
        if (a[i]-3>=6)
            a[i]-=3,ret++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<ret+sol(0,0,0)<<endl;

}