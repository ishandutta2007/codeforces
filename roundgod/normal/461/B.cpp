/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 02:11:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN];
vector<int> G[MAXN];
int dp[MAXN][2];//0:one black 1:no black
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int v)
{
    if(c[v]==1)
    {
        dp[v][1]=0;dp[v][0]=1;
        for(int i=0;i<(int)G[v].size();i++)
        {
            int to=G[v][i];
            dfs(to);
            dp[v][0]=1LL*dp[v][0]*(dp[to][1]+dp[to][0])%MOD;
        }
    }
    else
    {
        dp[v][0]=0;dp[v][1]=1;
        int s=1;
        for(int i=0;i<(int)G[v].size();i++)
        {
            int to=G[v][i];
            dfs(to);
            s=1LL*s*(dp[to][1]+dp[to][0])%MOD;
        }
        for(int i=0;i<(int)G[v].size();i++)
        {
            int to=G[v][i];
            if(dp[to][0]!=0) dp[v][0]=(dp[v][0]+1LL*s*pow_mod((dp[to][1]+dp[to][0]),MOD-2)%MOD*dp[to][0])%MOD;
            dp[v][1]=1LL*dp[v][1]*(dp[to][1]+dp[to][0])%MOD;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++) 
    {
        int x;
        scanf("%d",&x);x++;
        G[x].push_back(i);
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    dfs(1);
    //for(int i=1;i<=n;i++) printf("%d %d\n",dp[i][0],dp[i][1]);
    printf("%d\n",dp[1][0]);
    return 0;
}