#include<cstdio>
#include<algorithm>
#define mo 1000000007
using namespace std;
using LL=long long;

struct Finwick
{
	int n,C[100005];
	
	inline void init(int x)
	{
		n=x;
	}
	
	int sum(int x)
	{
		int res=0;
		while(x)
			res+=C[x],x-=x&-x;
		return res;
	}
	
	int add(int x, int d)
	{
		while(x<=n)
			C[x]+=d,x+=x&-x;
	}
}F;

int n,q,k,m,ans,rt,a[100005];
int rt_ans,h[100005],dp[305];
int dfs_clock,dfn[100005],son[100005];
int dep[100005],p[100005][18];
vector<int> E[100005];
bool mrk[100005];

void dfs(int i, int fa)
{
	dep[i]=dep[fa]+1;
	son[i]=1;
	p[i][0]=fa;
	for(int j=1;(1<<j)<dep[i];j++)
		p[i][j]=p[p[i][j-1]][j-1];
	dfn[i]=++dfs_clock;
	for(int v:E[i])
		if(v!=fa)
			dfs(v,i),son[i]+=son[v];
}

int LCA(int a, int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	int i,j,res=0;
	for(i=0;(1<<i)<dep[a];i++);
	i--;
	for(j=i;j>=0;j--)
		if(dep[a]-(1<<j)>=dep[b])
			a=p[a][j];
	if(a==b)
		return a;
	for(j=i;j>=0;j--)
		if(p[a][j]!=p[b][j])
			a=p[a][j],b=p[b][j];
	return p[a][0];

}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),E[u].push_back(v),E[v].push_back(u);
	dfs(1,0);
	while(q--)
	{
		scanf("%d%d%d",&k,&m,&rt);
		F.init(n);
		for(int i=1;i<=k;i++)  //
		{
			scanf("%d",&a[i]);
			mrk[a[i]]=true;
			F.add(dfn[a[i]],1);
			F.add(dfn[a[i]]+son[a[i]],-1);
		}
		rt_ans=F.sum(dfn[rt]);
		for(int i=1,lca;i<=k;i++)
		{
			lca=LCA(a[i],rt);
			h[i]=F.sum(dfn[a[i]])+rt_ans-2*F.sum(dfn[lca])+mrk[lca]-1;
		}
		sort(h+1,h+k+1);
		for(int i=1;i<=k;i++)
		{
			F.add(dfn[a[i]],-1);
			F.add(dfn[a[i]]+son[a[i]],1);
			mrk[a[i]]=false;
		}
		for(int i=0;i<=m;i++)
			dp[i]=0;
		dp[0]=1;
		for(int i=1;i<=k;i++)
			for(int j=min(i,m);j>=0;j--)
				if(j>h[i])
					dp[j]=((LL)dp[j]*(j-h[i])%mo+dp[j-1])%mo;
				else
					dp[j]=0;
		ans=0;
		for(int i=1;i<=m;i++)
			ans=(ans+dp[i])%mo;
		printf("%d\n",ans);
	}
	return 0;
}