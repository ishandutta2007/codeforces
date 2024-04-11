/*************************************************************************
    > File Name: C2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-24 12:24:52
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 20005
#define MAXK 55
#define MAXP 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p,a[MAXN],dp[MAXN][MAXK][MAXP];
void mx(int &x,int y) {x=max(x,y);}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);a[i]%=p;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int l=0;l<p;l++)
                dp[i][j][l]=-INF;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int l=0;l<p;l++)
            {
                if(dp[i][j][l]==-INF) continue;
                mx(dp[i+1][j][(l+a[i+1])%p],dp[i][j][l]);
                mx(dp[i+1][j+1][0],dp[i][j][l]+(l+a[i+1])%p);
            }
        }
    }
    printf("%d\n",dp[n][k][0]);
    return 0;
}