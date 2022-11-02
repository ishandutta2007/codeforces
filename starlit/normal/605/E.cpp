#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1003
#define eps 1e-8
#define inf 1e17
using namespace std;
typedef double db;
int n,x,mn;
bool vis[N];
db p[N][N],co[N],now[N],dp[N];
inline db cal(int x)
{return co[x]+eps<1?(now[x]+1)/(1-co[x]):inf;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&x),p[i][j]=x/100.0;
	for(int i=1;i<n;i++)co[i]=1;
	dp[0]=inf+1,now[n]=-1;
	for(int i=1;i<=n;i++)
	{
		mn=0;
		for(int j=1;j<=n;j++)
		if(!vis[j])
        ((dp[j]=cal(j))<dp[mn])?mn=j:0;
        if(mn==1)break;
		vis[mn]=1;
		for(int j=1;j<=n;j++)
		if(!vis[j])
		now[j]+=co[j]*p[j][mn]*dp[mn],
		co[j]*=1-p[j][mn];
	}
	printf("%.8lf",dp[1]);
}