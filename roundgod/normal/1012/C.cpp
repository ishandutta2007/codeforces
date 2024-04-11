/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-02 19:20:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int dp[MAXN][3000],pre[MAXN][3000];
int cost(int i,int j)
{
    if(a[i]<a[j]) return 0;
    else return a[i]-a[j]+1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++) for(int j=1;j<=(n+1)/2;j++) dp[i][j]=pre[i][j]=INF;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=cost(i-1,i);
        pre[i][1]=min(pre[i-1][1],dp[i][1]+cost(i+1,i));
        for(int j=2;j<=(i+1)/2;j++)
        {
            dp[i][j]=INF;
            dp[i][j]=min(dp[i][j],dp[i-2][j-1]+max(cost(i-1,i),cost(i-1,i-2)));
            if(i>=4) dp[i][j]=min(dp[i][j],pre[i-3][j-1]+cost(i-1,i)); 
            pre[i][j]=min(pre[i-1][j],dp[i][j]+cost(i+1,i));
        }
    }
    for(int i=1;i<=(n+1)/2;i++) printf("%d ",pre[n][i]);
    return 0;
}