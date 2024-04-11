#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=x;i<y;i++)
#define DRPT(i,x,y) for (REG int i=x;i>y;i--)
#define MST(a,b) memset(a,b,sizeof(a))
#define MRK() cout<<"Mark"<<endl; 
#define WRT(x) cout<<#x<<" = "<<x<<endl;
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 500000
#define MAXM 1000000
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
int n;
int flag[MAXN];
int cnt;
void init()
{
	int x;
	cin>>n;
	RPT(i,1,n+1)
		scanf("%d",&flag[i]);
	RPT(i,2,n+1)
	{
		cin>>x;
		g.add(x,i);
	}
}

int dfs(int pos)
{
	int tem;
	if (flag[pos]==1)
	{
		tem=INF;
		LINK(i,g,pos)
			tem=min(tem,dfs(g.to[i]));
		if (tem==INF)
		{
			cnt++;
			tem=1;
		}
	}
	else
	{
		tem=0;
		LINK(i,g,pos)
			tem+=dfs(g.to[i]);
		if (tem==0)
		{
			cnt++;
			tem=1;
		}
	}
	return tem;
}

int main()
{
	init();
	cnt+=1-dfs(1);
	cout<<cnt;
	return ~~(0^_^0);
}