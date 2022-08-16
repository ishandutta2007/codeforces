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
int n,m;
VI adj[100005];
VI adjd[100005];
VI pts[100005];

int dist[100005];
set<PII> q;

void solve()
{
	for(int i=0;i<n;i++)
		dist[i] = INF+INF;
		
	q.insert(mp(0,0));
	dist[0]=0;
	
	while(!q.empty())
	{
		PII top = *q.begin();
		q.erase(q.begin());
		int d = top.FF;
		int u = top.SS;
		
		if(d > dist[u]) continue;
		
		while(true)
		{
			int pos = INDEX( pts[u], d );
			if(pos < pts[u].size() && pts[u][pos]==d)
				d++;
			else
				break;
		}
		
		int k=adj[u].size();
		for(int i=0;i<k;i++)
		{
			int v = adj[u][i];
			int len = adjd[u][i];
			
			if(d+len < dist[v])
			{
				q.insert(mp(d+len, v));
				dist[v] = d+len;
			}
		}
	}
	
	if(dist[n-1] == INF+INF)
		dist[n-1] = -1;
	printf("%d\n", dist[n-1]);
		
		
}

bool input()
{
	s(n); s(m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		s(a); s(b); s(c);
		a--; b--;
		
		adj[a].pb(b);
		adj[b].pb(a);
		
		adjd[a].pb(c);
		adjd[b].pb(c);
	}
	
	for(int i=0;i<n;i++)
	{
		int k; s(k);
		for(int j=0;j<k;j++)
		{
			int x; s(x);
			pts[i].pb(x);
		}
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