#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
const int mod=1e9+7;
int stk[N],top;
int dp[N][N][3][3];//0->1->2->
int nxt[N];
string s,str;
int n,ans;
void dfs(int l,int r)
{
    //[l,r]DP
    if (r-l==1)
    {
        //lr
        dp[l][r][0][1]=1;
        dp[l][r][0][2]=1;
        dp[l][r][1][0]=1;
        dp[l][r][2][0]=1;
        return;
    }
    int m=nxt[l];
    if (m!=r)
    {
        //ir
        dfs(l,m);
        dfs(m+1,r);
        for (int i=0;i<=2;i++)  for (int j=0;j<=2;j++)
        for (int k=0;k<=2;k++)  for (int _=0;_<=2;_++) if (j!=k || j==0)//
        dp[l][r][i][_]+=dp[l][m][i][j]*dp[m+1][r][k][_],dp[l][r][i][_]%=mod;
	
    }
    else
    {
        dfs(l+1,r-1);
        for (int i=0;i<=2;i++) for (int j=0;j<=2;j++)
        {
            if (i!=1) dp[l][r][1][0]+=dp[l+1][r-1][i][j],dp[l][r][1][0]%=mod;
            if (i!=2) dp[l][r][2][0]+=dp[l+1][r-1][i][j],dp[l][r][2][0]%=mod;
            if (j!=1) dp[l][r][0][1]+=dp[l+1][r-1][i][j],dp[l][r][0][1]%=mod;
            if (j!=2) dp[l][r][0][2]+=dp[l+1][r-1][i][j],dp[l][r][0][2]%=mod;
        }
    }
}
signed main()
{
    cin>>s;
    str=" "+s;
    n=s.length();
    for (int i=1;i<=n;i++)
    {
        if (str[i]=='(') stk[++top]=i;
        else nxt[stk[top]]=i,top--;
    }
    dfs(1,n);
    for (int i=0;i<=2;i++) for (int j=0;j<=2;j++) ans+=dp[1][n][i][j],ans%=mod;
    cout<<ans<<endl;
}