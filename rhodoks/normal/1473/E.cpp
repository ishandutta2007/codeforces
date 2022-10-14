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

//#define BiDirction
#define LINK(i,g,pos) for (auto i:g[pos]) 
typedef pair<LL,int> pli;
class Graph
{
	int n,m,x,y; 
	LL w;
	vector<vector<pli>> g;
	vector<LL> dis;
public:
	
	Graph()
	{
		
	}
	
	Graph(int _n)
	{
		init(_n);
	}
	
	void init(int _n)
	{
		m=0;
		n=_n;
		g.resize(n+2);
		dis.resize(n+2);
	}
	
	void add(int x,int y,LL w)
	{
		m++;
		g[x].push_back({w,y});
	}
	
	void AddEdge(int x,int y,LL w)
	{
		add(x,y,w);
		#ifdef BiDirction
		add(y,x,w);
		#endif
	}
	
	
	void Dijkstra(int s)
	{
		priority_queue<pli,vector<pli>,greater<pli> > pq;
		for (int i=0;i<=n;i++)
			dis[i]=LLINF; 
		//memset(&dis[0],INF,sizeof(LL)*dis.size());
		pq.push({0,s});
		dis[s]=0;
		while (!pq.empty())
		{
			LL d=pq.top().first;
			int pos=pq.top().second;
			pq.pop();
			if (dis[pos]!=d)
				continue;
			for (auto p:g[pos])
			{
				if (dis[p.second]>dis[pos]+p.first)
				{
					dis[p.second]=dis[pos]+p.first;
					pq.push({dis[p.second],p.second});
				}
			}
		}
	}
	
	LL &Getdis(int x)
	{
		return dis[x];
	}
	
	
	void Readnm(int n,int m)
	{
		init(n);
		int cnt=m; 
		while (cnt--)
		{
			scanf("%d%d%lld",&x,&y,&w);
			AddEdge(x,y,w);
		}
	} 
	
	void Read()
	{
		scanf("%d%d",&n,&x);
		Readnm(n,x);
	}
	
	vector<pli> &operator[](int x)
	{
		return g[x];
	}
}; 

void work()
{
	int n,m,s;
	int x,y,w;
	cin>>n>>m;
	Graph g(4*n);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g.AddEdge(4*x,4*y,w);
		g.AddEdge(4*x-1,4*y-1,w);
		g.AddEdge(4*x-2,4*y-2,w);
		g.AddEdge(4*x-3,4*y-3,w);
		
		g.AddEdge(4*x,4*y-1,2*w);
		g.AddEdge(4*x-2,4*y-3,2*w);
		
		g.AddEdge(4*x,4*y-2,0);
		g.AddEdge(4*x-1,4*y-3,0);
		
		g.AddEdge(4*x,4*y-3,w);
		
		swap(x,y);
		
		g.AddEdge(4*x,4*y,w);
		g.AddEdge(4*x-1,4*y-1,w);
		g.AddEdge(4*x-2,4*y-2,w);
		g.AddEdge(4*x-3,4*y-3,w);
		
		g.AddEdge(4*x,4*y-1,2*w);
		g.AddEdge(4*x-2,4*y-3,2*w);
		
		g.AddEdge(4*x,4*y-2,0);
		g.AddEdge(4*x-1,4*y-3,0);
		
		g.AddEdge(4*x,4*y-3,w);
	}
	g.Dijkstra(4);
	for (int i=2;i<=n;i++)
		cout<<g.Getdis(4*i-3)<<' ';
 
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}