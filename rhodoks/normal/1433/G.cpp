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

int n,m,k;
int u[MAXN],v[MAXN],w[MAXN];
int a[MAXN],b[MAXN];
typedef pair<int,int> pii;
vector<pii> g[MAXN];
int dis[1010][1010];
void dijkstra(int s)
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0,s});
	dis[s][s]=0;
	while (!pq.empty())
	{
		int pos=pq.top().second;
		int posdis=pq.top().first;
		pq.pop();
		if (posdis!=dis[s][pos])
			continue;
		for (auto p:g[pos])
			if (dis[s][pos]+p.second<dis[s][p.first])
			{
				dis[s][p.first]=dis[s][pos]+p.second;
				pq.push({dis[s][p.first],p.first});
			}
	}
}

void work()
{
	cin>>n>>m>>k;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		g[u[i]].push_back({v[i],w[i]}); 
		g[v[i]].push_back({u[i],w[i]}); 
	}
	for (int i=0;i<k;i++)
		scanf("%d%d",&a[i],&b[i]);
	MST(dis,INF);
	for (int i=1;i<=n;i++)
		dijkstra(i);
	int ans=INF;
	for (int i=0;i<m;i++)
	{
		int tmp=0;
		for (int j=0;j<k;j++)
			tmp+=min(dis[a[j]][b[j]],min(dis[a[j]][u[i]]+dis[v[i]][b[j]],dis[a[j]][v[i]]+dis[u[i]][b[j]]));
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
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