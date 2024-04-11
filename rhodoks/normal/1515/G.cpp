#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m,x,y,w,q;
typedef pair<int,int> pii;
vector<pii> g[MAXN];
LL dis[MAXN];
LL gc[MAXN];;
int col[MAXN];


bool instak[MAXN];
int stak[MAXN];
int dfn[MAXN];
int low[MAXN];
int cnt;
int tim;
int visit[MAXN];

void tarjan(int x)
{
	stak[++cnt]=x;
	instak[x]=true;
	low[x]=dfn[x]=++tim;
	for (auto p:g[x])
	{
		int to=p.first;
		if (!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else
			if (instak[to])
				low[x]=min(low[x],dfn[to]);
	}
	if (dfn[x]==low[x])
		do
		{
			col[stak[cnt]]=x;
			instak[stak[cnt]]=false;
		}
		while (stak[cnt--]!=x);
}

LL gcd(LL x,LL y)
{
	return y==0 ? x:gcd(y,x%y);
}

void dfs(int pos,int c)
{
	visit[pos]=1;
	for (auto p:g[pos])
	{
		if (col[p.first]!=col[pos])
			continue;
		if (visit[p.first])
		{
			gc[c]=gcd(gc[c],dis[pos]-dis[p.first]+p.second);
			continue;
		}
		dis[p.first]=dis[pos]+p.second;
		dfs(p.first,c);
	}
}

void init()
{

}

void work()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({y,w});
	}
	for (int i=1;i<=n;i++)
		if (!col[i])
			tarjan(i);
	for (int i=1;i<=n;i++)
		if (!visit[i])
			dfs(i,col[i]);
	cin>>q;
	while (q--)
	{
		scanf("%d%d%d",&x,&y,&w);
		if (y%(gcd(gc[col[x]],(LL)w))==0)
			printf("YES\n");
		else
			printf("NO\n");
			
	}
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}