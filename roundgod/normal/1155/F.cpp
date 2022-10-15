#include<bits/stdc++.h>
#define MAXN 15
#define MAXM (1<<14)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
bool adj[MAXN][MAXN];
bool ear[MAXM][MAXN][MAXN];
int pre[MAXM][MAXN][MAXN];
int dp[MAXM];
pair<int,P> predp[MAXM];
int main()
{
	scanf("%d%d",&n,&m);
	memset(adj,false,sizeof(adj));
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v); u--; v--;
		adj[u][v]=adj[v][u]=true;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) 
			if(adj[i][j]) ear[0][i][j]=true;
	for(int mask=1;mask<(1<<n);mask++)
		for(int u=0;u<n;u++)
		{
			if(mask&(1<<u)) continue;
			for(int v=0;v<n;v++)
			{
				if(mask&(1<<v)) continue;
				for(int nxt=0;nxt<n;nxt++)
				{
					if(!(mask&(1<<nxt))) continue;
					if(ear[mask^(1<<nxt)][u][nxt]&&adj[nxt][v]&&(u!=v||mask^(1<<nxt)))
					{
						ear[mask][u][v]=true;
						pre[mask][u][v]=nxt;
					}
				}
			}
		}
	for(int i=0;i<(1<<n);i++) dp[i]=INF;
	dp[1]=0;
	for(int mask=2;mask<(1<<n);mask++)
		for(int sub=(mask-1)&mask;sub;sub=(sub-1)&mask)
			for(int i=0;i<n;i++)
			{
				if(!(sub&(1<<i))) continue;
				for(int j=0;j<n;j++)
				{
					if(!(sub&(1<<j))) continue;
				    if(!ear[mask^sub][i][j]) continue;
				    if(dp[sub]+1<dp[mask])
				    {
				        dp[mask]=dp[sub]+1;
				        predp[mask]=make_pair(mask^sub,P(i,j));
				    }
				}
			}
	printf("%d\n",dp[(1<<n)-1]+n-1);
	int now=(1<<n)-1;
	while(now!=1)
	{
		auto p=predp[now];
		int m=p.F,u=p.S.F,v=p.S.S;
		now^=m;
		while(m)
		{
			assert(ear[m][u][v]);
			int last=pre[m][u][v];
			assert(last>=0);
			assert(m&(1<<last));
			printf("%d %d\n",last+1,v+1);
			v=last;
			m^=(1<<last);
		}
		printf("%d %d\n",u+1,v+1);
	}
	return 0;
}