#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}





typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;


/*Main code begins now */

int testnum;
	
int T;
const int MAXN=2000;
VI adjList[MAXN],rmap[MAXN];
VI cost[MAXN],cap[MAXN];
int deg[MAXN];

void initFlow(int _T)
{
	T=_T;
	fill(deg,0);
	for(int i=0;i<T;i++)
	{
		adjList[i].clear();
		rmap[i].clear();
		cost[i].clear();
		cap[i].clear();
	}
}
	
int addEdge(int a, int b, int cap1, int cap2, int cost1, int cost2)
{
	int ret = deg[a];
	rmap[a].pb(deg[b]);		rmap[b].pb(deg[a]);
	adjList[a].pb(b);		adjList[b].pb(a);
	cap[a].pb(cap1);		cap[b].pb(cap2);
	cost[a].pb(cost1);		cost[b].pb(cost2);
	deg[a]++;				deg[b]++;
	assert(cost1+cost2==0);
	return ret;
}	

// Returns cost of sending need flow, -INF if its impossible
int minCostFlow(int src, int dest, int need)
{
	int C=0;		
	VI dist(T);
	VI parent(T);
	VI done(T);
	
	while( need > 0)
	{
		for(int i=0;i<T;i++)
		{
			dist[i]=INF;
			parent[i]=-1;
			done[i]=false;
		}
		dist[src] = 0;
		
		while(true)
		{
			bool changed = false;
			for(int i = 0; i < T; i++)
			{
				if(done[i] || dist[i]>=INF) continue;
				done[i]=true;
				for(int j = 0; j < adjList[i].size(); j++)
				{
					int v = adjList[i][j];
					if( dist[v] > dist[i] + cost[i][j] && cap[i][j] > 0)
					{
						dist[v] = dist[i] + cost[i][j];
						parent[v] = rmap[i][j];	done[v]=false;
						changed = true;
					}
				}
			}
			if (!changed) break;
		}		
		if( dist[dest]  ==  INF) break;
		
		C += dist[dest];
		need--;
		int v=dest;
		while(v!=src)
		{
			int indv = parent[v];
			int u = adjList[v][indv];
			int indu = rmap[v][indv];			
			cap[u][indu]--;
			cap[v][indv]++;			
			v=u;
		}
	}
		
	if( need > 0) return -INF;
	return C;
}

int n,k;
int b[1000],e[1000],c[1000];
int z;
int ind[1005];

void solve()
{
	initFlow(z);
	for(int i=0;i+1<z;i++)
		addEdge(i,i+1,INF,0,0,0);
	for(int i=0;i<n;i++)
		ind[i]=addEdge(b[i],e[i],1,0,-c[i],c[i]);
	
	int ans = minCostFlow(0,z-1,k);
	for(int i=0;i<n;i++)
	{
		int u=b[i];
		if(cap[u][ind[i]])
			printf("0 ");
		else
			printf("1 ");
	}
}

bool input()
{
	s(n); s(k);
	VI tm;
	for(int i=0;i<n;i++)
	{
		s(b[i]);
		s(e[i]);
		e[i]=e[i]+b[i];
		s(c[i]);
		tm.pb(b[i]);
		tm.pb(e[i]);
	}
	DREP(tm);
	for(int i=0;i<n;i++)
	{
		b[i]=INDEX(tm,b[i]);
		e[i]=INDEX(tm,e[i]);
	}
	z=tm.size();
	return true;
}

int main()
{
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}