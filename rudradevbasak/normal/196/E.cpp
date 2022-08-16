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
typedef pair<LL,int> PLI;
typedef pair<LL,PII> TRI;

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
int N,M;
VI adjl[100005];
VI adjd[100005];
int K;
bool isp[100005];

LL dist[100005];
int par[100005];
int rank[100005];
set<PLI> q;
VT edges;


void initUnionFind()
{
	for(int i=0;i<N;i++)
	{
		rank[i]=1;
		par[i]=i;
	}
}

int find(int x)
{
	if(par[x]==x) return x;
	return par[x] = find(par[x]);
}

bool unite(int u,int v)
{
	u = find(u);
	v = find(v);
	if(u==v) return false;
	
	if(rank[u]>rank[v])
	{
		par[v]=u;
		rank[u]+=rank[v];
	}
	else
	{
		par[u]=v;
		rank[v]+=rank[u];
	}
	return true;
}




void solve()
{
	for(int i=0;i<N;i++)
	{
		dist[i]=(LL)1e18;
		if(isp[i])
		{
			dist[i]=0;
			par[i]=i;
			q.insert(mp(0,i));
		}
	}
	
	while(!q.empty())
	{
		PLI top = *q.begin();
		q.erase(q.begin());
		int u = top.SS;
		LL d = top.FF;
		if(d>dist[u]) continue;
		
		int deg = adjl[u].size();
		for(int i=0;i<deg;i++)
		{
			int v = adjl[u][i];
			LL vd = adjd[u][i] + d;
			if(dist[v] > vd)
			{
				dist[v] = vd;
				par[v] = par[u];
				q.insert(mp(vd,v));
			}
		}
	}
	
	LL ans = dist[0];
	for(int i=0;i<M;i++)
	{
		int a=edges[i].YY;
		int b=edges[i].ZZ;
		edges[i] = tri(edges[i].XX+dist[a]+dist[b],par[a],par[b]);
	}
	
	sort(all(edges));
	initUnionFind();
	for(int i=0;i<M;i++)
	{
		int a=edges[i].YY;
		int b=edges[i].ZZ;
		if(unite(a,b))
			ans += edges[i].XX;
	}
	cout<<ans<<endl;
}

bool input()
{
	s(N); s(M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		s(a); s(b); s(c);
		a--;
		b--;
		edges.pb(tri(c,a,b));
		adjl[a].pb(b);
		adjl[b].pb(a);
		adjd[a].pb(c);
		adjd[b].pb(c);
	}
	s(K);
	fill(isp,false);
	for(int i=0;i<K;i++)
	{
		int x; s(x); x--;
		isp[x]=true;
	}
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