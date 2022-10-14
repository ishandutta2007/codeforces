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

#define MAXN 1001000
#define MAXM 2010000
#define MOD 1000000007
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
int pa[MAXN];
int c[MAXN];
int n,root;
int size[MAXN];
int ans[MAXN];
vector<int> v[MAXN];
void init()
{
	int x,y;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,i);
		pa[i]=x;
		c[i]=y;
		if (pa[i]==0)
			root=i; 
	}
}

void dfs(int pos)
{
	size[pos]=1;
	LINK(i,g,pos)
	{
		dfs(g.to[i]);
		size[pos]+=size[g.to[i]]; 
	}
	//cout<<pos<<' '<<c[pos]<<' '<<size[pos]<<endl;
	if (c[pos]+1>size[pos])
	{
		cout<<"NO";
		exit(0);
	}
}

void dfs1(int pos)
{
	LINK(i,g,pos)
	{
		dfs1(g.to[i]);
		for (auto p:v[g.to[i]])
			v[pos].push_back(p);
	}
	v[pos].insert(v[pos].begin()+c[pos],pos);
}


int main()
{
	init();
	dfs(root);
	dfs1(root);
	int cnt=1;
	for (auto p:v[root])
		ans[p]=cnt++;
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return ~~(0^_^0);
}