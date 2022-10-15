/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 22:38:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define REV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int dp[MAXN][MAXN],res[MAXN];
int _mod(int x){return x>=MOD?x-MOD:x;}
int main()
{
    scanf("%d%d",&n,&k);
    for(int p=1;p<=n;p++)
    {
        memset(dp,0,sizeof(dp));
        dp[1][1]=2;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=min(i,p);j++) dp[i][1]=_mod(dp[i][1]+dp[i-1][j]);
            for(int j=2;j<=min(i,p);j++) dp[i][j]=dp[i-1][j-1];
        }
        for(int i=1;i<=p;i++) res[p]=_mod(res[p]+dp[n][i]);
        //printf("%d\n",res[p]);
    }
    for(int i=n;i>=1;i--) 
    {
        res[i]-=res[i-1];
        if(res[i]<0) res[i]+=MOD;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i*j<k) ans=(ans+1LL*res[i]*res[j]%MOD*REV)%MOD;
    printf("%d\n",ans);
    return 0;
}