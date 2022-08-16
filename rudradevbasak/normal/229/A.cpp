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
char str[100][10005];
int nxt[100][10005];
int prev[100][10005];

int dist(int a,int b)
{
	int diff = abs(b-a);
	return min(diff,C-diff);
}

void solve()
{
	fill(nxt,-1);
	fill(prev,-1);
	
	for(int i=0;i<R;i++)
	{
		for(int rounds=0;rounds<2;rounds++)
		{
			for(int j=0;j<C;j++)
			{
				int pj = (j-1+C)%C;
				if(str[i][j]=='1')
					prev[i][j]=j;
				else
					prev[i][j]=prev[i][pj];
			}
			
			for(int j=C-1;j>=0;j--)
			{
				int pj = (j+1)%C;
				if(str[i][j]=='1')
					nxt[i][j]=j;
				else
					nxt[i][j]=nxt[i][pj];
			}
		}
		
		if(prev[i][0]<0) 
		{
			printf("-1\n");
			return;
		}
	}
	
	int ans = INF;
	for(int c=0;c<C;c++)
	{
		int sum=0;
		for(int r=0;r<R;r++)
		{
			int p = prev[r][c];
			int n = nxt[r][c];
			sum += min( dist(c,p), dist(c,n) );
		}
		ans = min(ans, sum);
	}
	
	printf("%d\n",ans);
		
}

bool input()
{
	s(R);
	s(C);
	for(int i=0;i<R;i++)
		ss(str[i]);
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