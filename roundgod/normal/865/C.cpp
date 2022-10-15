#include<bits/stdc++.h>
#define MAXN 55
#define MAXT 5500
#define eps 1e-9
#define INF 100000000000
using namespace std;
double dp[MAXN][MAXT];
int n,r;
int f[MAXN],s[MAXN];
double p[MAXN];
int main()
{
    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %lf",&f[i],&s[i],&p[i]);
        p[i]/=100;
    }
    double left=0,right=1e10;
    for(int k=0;k<200;k++)
    {
        double mid=(left+right)/2;
        memset(dp,0,sizeof(dp));
        for(int j=0;j<=r;j++) dp[n][j]=j;
        for(int j=r+1;j<MAXT;j++) dp[n][j]=INF;
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<MAXT-100;j++)
               dp[i][j]=(min(mid+f[i]+j,dp[i+1][j+f[i]]))*p[i]+(min(mid+s[i]+j,dp[i+1][j+s[i]]))*(1-p[i]);
        if(dp[0][0]<mid) right=mid; else left=mid;
    }
    printf("%.10lf\n",left);
    return 0;
}