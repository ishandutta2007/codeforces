/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 01:11:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h,a[MAXN],dp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&h);
    bool f=true;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        a[i]=h-a[i];
        if(a[i]<0) f=false;
    }
    if(!f) {puts("0"); return 0;}
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            if(j==a[i]-1) 
            {   
                dp[i+1][j]=(dp[i+1][j]+1LL*dp[i][j]*(j+1))%MOD; 
                (dp[i+1][j+1]+=dp[i][j])%=MOD;
                continue;
            }
            if(j!=a[i]) continue;
            (dp[i+1][j]+=dp[i][j])%=MOD;
            if(j>0) dp[i+1][j-1]=(dp[i+1][j-1]+1LL*j*dp[i][j])%MOD;
        }
    }
    printf("%d\n",dp[n+1][0]);
    return 0;
}