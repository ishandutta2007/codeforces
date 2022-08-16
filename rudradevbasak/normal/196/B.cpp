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
int R,C;
char grid[1505][1505];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool done[1505][1505];
int X[1505][1505];
int Y[1505][1505];
bool found;

void dfs(int a,int b,int curx,int cury)
{
	done[a][b]=true;
	X[a][b]=curx;
	Y[a][b]=cury;
	for(int k=0;k<4;k++)
	{
		int x=(a+dx[k]+R)%R;
		int y=(b+dy[k]+C)%C;
		int nxtx = curx;
		int nxty = cury;
		if(a+dx[k]<0) nxtx--;
		if(a+dx[k]>=R) nxtx++;
		if(b+dy[k]<0) nxty--;
		if(b+dy[k]>=C) nxty++;
		//if(x<0 || y<0 || x>=R || y>=C) continue;
		if(grid[x][y]=='#') continue;
		if(done[x][y])
		{
			if(nxtx!=X[x][y] || nxty!=Y[x][y])
				found=true;
			continue;
		}
		dfs(x,y,nxtx,nxty);
	}
}

void solve()
{
	int begx,begy;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(grid[i][j]=='S')
			{
				begx=i;
				begy=j;
			}
	
	fill(done,false);
	found=false;
	dfs(begx,begy,0,0);
	
		
	printf("%s\n",found?"Yes":"No");
	
		
}

bool input()
{
	s(R); s(C);
	for(int i=0;i<R;i++)
		ss(grid[i]);
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