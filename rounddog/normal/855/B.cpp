#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 500500
#define inf 1000000020

using namespace std;
typedef long long ll;

ll dp[maxn][4],a[maxn],b[4],n;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<4;i++) scanf("%I64d",&b[i]);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    dp[0][1]=dp[0][2]=dp[0][3]=-(ll)inf*inf*5;
    for (int j=1;j<4;j++)
        for (int i=1;i<=n;i++)
            dp[i][j]=max(dp[i][j-1]+a[i]*b[j],dp[i-1][j]);
    printf("%I64d\n",dp[n][3]);
    return 0;
}