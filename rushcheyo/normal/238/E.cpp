#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,a,b,k,s[105],t[105],g[105][105],cnt[105],dp[105][105];
bool must[105][105];
bool on(int i,int j)
{
	return g[s[i]][j]+g[j][t[i]]==g[s[i]][t[i]];
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),g[u][v]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",s+i,t+i);
		if(g[s[i]][t[i]]>=n)continue;
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++)
			if(on(i,j))
				cnt[g[s[i]][j]]++;
		for(int j=1;j<=n;j++)
			if(on(i,j)&&cnt[g[s[i]][j]]==1)
				must[i][j]=true;
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=k;i++)
		if(on(i,b))dp[i][b]=1;
	for(;;)
	{
		bool f=false;
		for(int j=1;j<=k;j++)
			for(int i=1;i<=n;i++)
				if(on(j,i))
				{
					if(i==b)continue;
					int ma=-1;
					for(int x=1;x<=n;x++)
						if(g[i][x]==1&&g[x][t[j]]+1==g[i][t[j]])ma=max(ma,dp[j][x]);
					if(ma!=-1&&ma<dp[j][i])dp[j][i]=ma,f=true;
					for(int x=1;x<=k;x++)
						if(must[x][i]&&x!=j&&dp[x][i]+1<dp[j][i])dp[j][i]=dp[x][i]+1,f=true;
				}
		if(!f)break;
	}
	int ans=inf;
	for(int i=1;i<=k;i++)if(must[i][a])ans=min(ans,dp[i][a]);
	printf("%d\n",ans==inf?-1:ans);
}