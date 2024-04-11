/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 17:38:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1e15
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tc,n;
double C,T;
P a[MAXN];
double dp[105][105][1005];
double p[105];
void relax(double &a,const double &b) {a=min(a,b);}
int main()
{
    scanf("%d",&tc);
    p[0]=1;
    for(int i=1;i<=100;i++) p[i]=0.9*p[i-1];
    while(tc--)
    {
        scanf("%d",&n);
        scanf("%lf%lf",&C,&T);
        int s=0;
        for(int i=1;i<=n;i++) {scanf("%d%d",&a[i].F,&a[i].S); s+=a[i].S;}
        sort(a+1,a+n+1,greater<>());
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=s;k++)
                    dp[i][j][k]=INF;
        dp[0][0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=s;k++)
                {
                    if(dp[i][j][k]==INF) continue;
                    relax(dp[i+1][j][k],dp[i][j][k]);
                    relax(dp[i+1][j+1][k+a[i+1].S],dp[i][j][k]+a[i+1].F/p[j+1]);
                }
            }
        }
        for(int i=s;i>=0;i--)
        {
            if(i==0) {puts("0"); break;}
            bool f=false;
            for(int j=0;j<=n;j++) 
            {
                if(dp[n][j][i]==INF) continue;
                double curmin=dp[n][j][i],ans;
                if(curmin==0) ans=0;
                else
                {
                    double pt=sqrt(curmin/C)-1/C;
                    if(pt>=0) ans=2*sqrt(curmin/C)-1/C;
                    else ans=curmin;
                }
                //printf("%d %d %lf %lf\n",i,j,curmin,ans+j*10);
                if(ans+j*10<=T) {f=true; break;}
            }
            if(f) {printf("%d\n",i); break;}
            assert(i!=0);
        }
    }
    return 0;
}