#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl; 
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 3010
#define MAXM 20100
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM],from[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y)
	{
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;
int n;
int size[MAXN][MAXN];
int pa[MAXN][MAXN];
LL dp[MAXN][MAXN];

int ancestor;

void dfs(int pos,int f)
{
	pa[ancestor][pos]=f;
	size[ancestor][pos]=1;
	LINK(i,g,pos)
		if (g.to[i]!=f)
		{
			dfs(g.to[i],pos);
			size[ancestor][pos]+=size[ancestor][g.to[i]];
		}
}

void init()
{
	int x,y;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
	}
	for (ancestor=1;ancestor<=n;ancestor++)
		dfs(ancestor,ancestor); 
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)
				dp[i][j]=-1;
}


LL ans;

LL getdp(int u,int v)
{
	if (dp[u][v]!=-1)
		return dp[u][v];
	return dp[u][v]=(LL)size[u][v]*size[v][u]+max(getdp(pa[v][u],v),getdp(u,pa[u][v]));
}

void work()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			ans=max(ans,getdp(i,j));
	cout<<ans;
}

int main()
{
	init();
	work();
	return ~~(0^_^0);
}