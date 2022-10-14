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

#define MAXN 401000
#define MAXM 801000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM];
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


LL a[MAXN];
LL n;
LL son[MAXN];
LL pa[MAXN];
LL dp[MAXN];

void dfs1(int pos,int fa)
{
	pa[pos]=fa;
	LINK(i,g,pos)
		if (g.to[i]!=fa)
		{
			son[pos]++;
			dfs1(g.to[i],pos);
		}
}

LL dfs2(int pos)
{
	if (son[pos]==0)
		return dp[pos]=1;
	if (pos!=1)
		dp[pos]=a[son[pos]+1];
	else
		dp[pos]=a[son[pos]];
	LINK(i,g,pos)
		if (g.to[i]!=pa[pos])
			dp[pos]=dp[pos]*dfs2(g.to[i])%MOD;
	return dp[pos];
}

void init()
{
	a[0]=1;
	RPT(i,1,MAXN)
		a[i]=a[i-1]*i%MOD;
	cin>>n;
	int x,y;
	RPT(i,0,n-1)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
	}
}

int main()
{
	init();
	dfs1(1,1);
	dfs2(1);
	cout<<dp[1]*n%MOD;
	return ~~(0^_^0);
}