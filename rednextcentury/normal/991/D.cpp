#include<bits/stdc++.h>
using namespace std;
int n;
string s[2];
int dp[1000][5];
int msk[1000];
int solve(int i,int st)
{
    if (i==n-1)return 0;
    if (dp[i][st]!=-1)
        return dp[i][st];
    if (st==3)return dp[i][st]=solve(i+1,msk[i+1]);
    else if (st==2 || st==1)
    {
        if (msk[i+1]==0)
            return dp[i][st]=max(solve(i+1,msk[i+1]),solve(i+1,3)+1);
        else
            return dp[i][st]=solve(i+1,msk[i+1]);
    }
    else
    {
        if (msk[i+1]==0)
            return dp[i][st]=max(max(solve(i+1,msk[i+1]),solve(i+1,1)+1),max(solve(i+1,2)+1,solve(i+1,3)+1));
        else if (msk[i+1]==1 || msk[i+1]==2)
            return dp[i][st]=max(solve(i+1,msk[i+1]),solve(i+1,3)+1);
        else
            return dp[i][st]=solve(i+1,msk[i+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s[0]>>s[1];
    n=s[0].size();
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<n;i++)
    {
        if (s[0][i]=='X')msk[i]++;
        if (s[1][i]=='X')msk[i]+=2;
    }
    cout<<solve(0,msk[0])<<endl;
}