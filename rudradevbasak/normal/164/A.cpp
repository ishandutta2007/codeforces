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
const int MAXN=100005;
VI adjl[MAXN];
VI radjl[MAXN];
bool done[MAXN];
bool a[MAXN];
bool b[MAXN];
int n,m;
int z[MAXN];

void dfs1(int u)
{
	done[u]=true;
	a[u]=true;
	int k=adjl[u].size();
	for(int i=0;i<k;i++)
	{
		int v=adjl[u][i];
		if((z[v]==0 || z[v]==2) && !done[v])
			dfs1(v);
	}
}

void dfs2(int u)
{
	done[u]=true;
	b[u]=true;
	if(z[u]==1) return;
	int k=radjl[u].size();
	for(int i=0;i<k;i++)
	{
		int v=radjl[u][i];
		if(!done[v])
			dfs2(v);
	}
}
	
	

void preprocess()
{

}

void solve()
{
	fill(a,false);
	fill(b,false);
	
	fill(done,false);
	for(int i=0;i<n;i++)
		if(z[i]==1)
			dfs1(i);
	
	fill(done,false);
	for(int i=0;i<n;i++)
		if(z[i]==2)
			dfs2(i);
			
	for(int i=0;i<n;i++)
	{
		if(z[i]==0)
		{
			if(a[i] && b[i]) printf("1 ");
			else printf("0 ");
		}
		else if(z[i]==1)
		{
			if(b[i]) printf("1 ");
			else printf("0 ");
		}
		else if(z[i]==2)
		{
			if(a[i]) printf("1 ");
			else printf("0 ");
		}
	}
	printf("\n");
		
}



bool input()
{
	s(n); s(m);
	for(int i=0;i<n;i++)
		s(z[i]);
	for(int i=0;i<m;i++)
	{
		int x,y;
		s(x); s(y);
		x--; y--;
		adjl[x].pb(y);
		radjl[y].pb(x);
	}
	//for(int i=0;i<n;i++)
	//	debug(adjl[i],radjl[i]);
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}