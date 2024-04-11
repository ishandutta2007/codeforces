#include<bits/stdc++.h>
using namespace std;
char a[501][501];
char ret[501][501];
int num[501][2][26];
int ALPHA = 26;
int dp[501][26][26];
int n,m;
int solve(int i,int e,int o)
{
    if (e==o)return -1000000;
    if (i==n) return 0;
    if (dp[i][e][o]!=-1)return dp[i][e][o];
    int &ret = dp[i][e][o];
    ret=-1000000;
    for (int j=0;j<ALPHA;j++)
    {
        if (j==e)continue;
        for (int k=0;k<ALPHA;k++)
        {
            if (j==k || k==o)continue;
            ret=max(ret,num[i][0][e]+num[i][1][o]+solve(i+1,j,k));
        }
    }
    return ret;
}
int printPath(int i,int e,int o)
{
    if (i==n) return 0;
    for (int j=0;j<ALPHA;j++)
    {
        if (j==e)continue;
        for (int k=0;k<ALPHA;k++)
        {
            if (j==k || k==o)continue;
            if (num[i][0][e]+num[i][1][o]+solve(i+1,j,k) == dp[i][e][o])
            {
                for (int l=0;l<m;l++)
                {
                    if (l%2==0)cout<<char('a'+e);
                    else cout<<char('a'+o);
                }
                cout<<endl;
                return printPath(i+1,j,k);
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        for (int j=0;j<m;j++)
            num[i][j%2][a[i][j]-'a']++;
    }
    memset(dp,-1,sizeof(dp));
    int ret=0;
    for (int i=0;i<ALPHA;i++)
        for (int j=0;j<ALPHA;j++)
            if (i!=j)
                ret=max(ret,solve(0,i,j));
    cout<<n*m-ret<<endl;
    for (int i=0;i<ALPHA;i++)
        for (int j=0;j<ALPHA;j++)
            if (dp[0][i][j]==ret)
                return printPath(0,i,j);
}