#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long double ld;
const int N=110;
int n;
int siz[N];
ld C[N][N],dp[N][N],sum[N],tmp[N],h[N];
vector<int> e[N];
void dfs(int x,int nf)
{
	int i,j;
	siz[x]=0;
	dp[x][0]=1;
	for(int v:e[x])
	{
		if(v==nf) continue;
		dfs(v,x);
		for(i=0;i<=siz[v];i++) 
		{
			tmp[i]=0;
			sum[i]=dp[v][i];
			if(i>0) sum[i]+=sum[i-1];
		}
		for(i=0;i<=siz[v]-1;i++) tmp[i]+=dp[v][i]*(ld)(siz[v]-i);
		for(i=1;i<=siz[v];i++) tmp[i]+=sum[i-1]*0.5;
		for(i=0;i<=siz[x]+siz[v];i++) h[i]=0;
		for(i=0;i<=siz[x];i++)
		{
			for(j=0;j<=siz[v];j++)
			{
				h[i+j]+=dp[x][i]*tmp[j]*C[i+j][i]*C[siz[x]-i+siz[v]-j][siz[x]-i];
			}
		}
		for(i=0;i<=siz[x]+siz[v];i++) dp[x][i]=h[i];
		siz[x]+=siz[v];
	}
	siz[x]++;
}
int main()
{
	int i,j,u,v;
	ld ans,V;
	scanf("%d",&n);
	V=1;
	for(i=1;i<n;i++) V*=i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	for(i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
		dfs(i,0);
		ans=dp[i][n-1]/V;
		printf("%.10lf\n",(double)ans);
	}
	return 0;
}