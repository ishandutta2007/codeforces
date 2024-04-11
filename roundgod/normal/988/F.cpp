/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 17:25:13
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,m,n,k,dp[MAXN][MAXN],l[MAXN],r[MAXN],x[MAXN],p[MAXN];
bool rain[MAXN];
P w[MAXN];
int main()
{
    memset(rain,false,sizeof(rain));
    scanf("%d%d%d",&a,&n,&m);
    for(int i=0;i<=a;i++) w[i]=P(-1,-1);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        for(int j=l[i];j+1<=r[i];j++)
            rain[j]=true;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&p[i]);
        if(w[x[i]].F==-1||w[x[i]].F>p[i])
        {
            w[x[i]].F=p[i];
            w[x[i]].S=i;
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    if(w[0].F!=-1) dp[0][w[0].S]=0;
    for(int i=1;i<=a;i++)
    {
        if(rain[i-1])
        {
            int x=INF;
            for(int j=1;j<=m;j++)
            {
                if(dp[i-1][j]!=-1) 
                {
                    dp[i][j]=dp[i-1][j]+p[j];
                    x=min(x,dp[i][j]);
                }
                else dp[i][j]=-1;
            }
            if(x==INF) x=-1;
            dp[i][0]=x;
            if(w[i].F!=-1) dp[i][w[i].S]=x;
        }
        else
        {
            int x=INF;
            for(int j=0;j<=m;j++)
                if(dp[i-1][j]!=-1) 
                {
                    dp[i][j]=dp[i-1][j]+p[j];
                    x=min(x,dp[i-1][j]);
                }
            if(x==INF) x=-1;
            dp[i][0]=x;
            if(w[i].F!=-1) dp[i][w[i].S]=x;
        }
    }
    if(dp[a][0]==-1) puts("-1"); else printf("%d\n",dp[a][0]);
    return 0;
}