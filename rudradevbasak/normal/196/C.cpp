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

const double PI = 4*atan(1);

int testnum;
struct Point
{
	LL x,y;
	int i;
	double angle;
	Point(){}
	Point(LL xx,LL yy,int ii)
	{
		x=xx;
		y=yy;
		i=ii;
	}
	
	void setAngle(Point base,double baseAngle)
	{
		angle = atan2(y-base.y,x-base.x) - baseAngle;
		while(angle<-PI)
			angle += 2*PI;
		while(angle>+PI)
			angle -= 2*PI;
	}
};

bool operator < (Point a,Point other)
{
	return a.angle < other.angle;
}
	
bool operator == (Point a,Point b)
{
	return a.x==b.x && a.y==b.y;
}

typedef vector<Point> VP;





VI adj[1505];
Point pts[1505];
int vertex[1505];
int cnt[1505];
int n;
bool done[1505];


int dfs(int u)
{
	done[u]=true;
	cnt[u]=1;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(!done[v])
			cnt[u] += dfs(v);
	}
	return cnt[u];
}
		

void assign(int u,int ind,Point par,VP p)
{
	done[u]=true;
	vertex[ind]=u;
	Point cur = pts[ind];
	double baseAngle = atan2(cur.y-par.y,cur.x-par.x);
	
	int k=p.size();
	for(int i=0;i<k;i++)
		p[i].setAngle(cur,baseAngle);
	sort(all(p));
	
	int start=0;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(done[v]) continue;
		int nstart = start+cnt[v];
		VP nxt;
		for(int j=start+1;j<nstart;j++)
			nxt.pb(p[j]);
		assign(v,p[start].i,cur,nxt);
		start=nstart;
	}
}
		
	
	
	
	
	
	


void solve()
{
	fill(done,false);
	dfs(0);
	
	Point cur = Point(-1e12,-1e12,-1);
	double best = 4*PI;
	Point bp;
	VP nxt;
	for(int i=0;i<n;i++)
	{
		double angle = atan2(pts[i].y-cur.y, pts[i].x-cur.x);
		if(angle<best)
		{
			best=angle;
			bp=pts[i];
		}
	}
	
	for(int i=0;i<n;i++)
		if(bp.i != pts[i].i)
			nxt.pb(pts[i]);
	fill(done,false);
	assign(0,bp.i,cur,nxt);
	
	/*
	for(int i=0;i<n;i++)
		if(n==1500)
			printf("%d %d\n",(int)(pts[vertex[i]].x), (int)(pts[vertex[i]].y));
	*/
	
	for(int i=0;i<n;i++)
		printf("%d ",vertex[i]+1);
	printf("\n");
	
	
		
}

bool input()
{
	s(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		s(a); s(b);
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i=0;i<n;i++)
	{
		int x,y;
		s(x); s(y);
		pts[i] = Point(x,y,i);
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