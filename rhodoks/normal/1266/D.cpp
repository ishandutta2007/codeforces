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

#define MAXN 201000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM],from[MAXN];
		LL weight[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y,LL w)
	{
		from[cnt]=x;
		weight[cnt]=w;
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;

int n,m;
int x,y;
LL w;
/*
bool visit[MAXN];
int depth[MAXN];
int stak[MAXN];
int top=0;
bool instak[MAXN];
int plus[MAXN];

void dfs(int pos)
{
	instak[pos]=1;
	depth[pos]=depth[f]+1;
	visit[pos]=1;
	stak[++top]=pos;
	LINK(i,g,pos)
		if (g.weight[i]!=0)
		{
			if (!visit[g.to[i]])
				dfs(g.to[i]);
			else
			{
				if (instak[g.to[i]])
				{
					plus[g.to[i]]+=1;
				}
			}
		}
	instak[pos]=0;
}
*/
LL in[MAXN];
int ord[MAXN];

bool cmp(int x,int y)
{
	return in[x]<in[y];
}

int main()
{
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%lld",&x,&y,&w);
		in[x]-=w;
		in[y]+=w;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (in[i])
		{
			ord[++cnt]=i;
		}
	sort(ord+1,ord+1+cnt,cmp);
	//for (int i=1;i<=cnt;i++)
	//	cout<<ord[i]<<' '<<in[ord[i]]<<endl;
	int l=1;
	int r=cnt;
	while (l<r)
	{
		if (-in[ord[l]]>in[ord[r]])
		{
			g.add(ord[l],ord[r],in[ord[r]]);
			in[ord[l]]+=in[ord[r]];
			in[ord[r]]=0;
			r--;
		}
		else 
		{
			g.add(ord[l],ord[r],-in[ord[l]]);
			in[ord[r]]+=in[ord[l]];
			in[ord[l]]=0;
			l++;
			if (in[ord[r]]==0)
				r--;
		}
	}
	cout<<g.cnt-1<<endl;
	for (int i=1;i<g.cnt;i++)
		printf("%d %d %lld\n",g.from[i],g.to[i],g.weight[i]);
	return ~~(0^_^0);
}