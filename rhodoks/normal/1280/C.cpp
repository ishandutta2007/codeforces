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

#define MAXN 601000
#define MAXM 1210000
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
		int weight[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y,int w)
	{
		weight[cnt]=w;
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;

int n;
LL good,bad;
int size[MAXN];

void init()
{
	good=bad=0;
	cin>>n;
	memset(g.head,0,sizeof(int)*(2*n+3));
	int x,y,w;
	for (int i=0;i<2*n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g.add(x,y,w);
		g.add(y,x,w);
	}
}

int dfs(int pos,int pa)
{
	size[pos]=1;
	int cnt=0;
	LINK(i,g,pos)
		if (g.to[i]!=pa)
		{
			int x=dfs(g.to[i],pos);
			size[pos]+=size[g.to[i]];
			cnt+=x;
			if (x)
				good+=g.weight[i];
			//cout<<g.weight[i]<<' '<<size[g.to[i]]<<' '<<bad<<endl;
			bad+=(LL)g.weight[i]*min(size[g.to[i]],2*n-size[g.to[i]]);
		}
	return ((cnt & 1) ^ 1);
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		init();
		dfs(1,1);
		cout<<good<<' '<<bad<<endl;
	}
	return ~~(0^_^0);
}