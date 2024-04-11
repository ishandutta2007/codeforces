/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-29 20:51:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n;
db p[MAXN][MAXN];
db dp[(1<<18)][20];
db solve(int mask,int winner)
{
    if(dp[mask][winner]!=-1) return dp[mask][winner];
    if(mask==(1<<n)-1) return dp[mask][winner]=(winner==0?1:0);
    db ans=0;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        ans=max(ans,p[i][winner]*solve(mask|(1<<i),i)+p[winner][i]*solve(mask|(1<<i),winner));
    }
    return dp[mask][winner]=ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%Lf",&p[i][j]);
    for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j]=-1;
    db ans=0;
    for(int i=0;i<n;i++) ans=max(ans,solve((1<<i),i));
    printf("%.10Lf\n",ans);
    return 0;
}