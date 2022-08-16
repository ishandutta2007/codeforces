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
int n,r;

PII get(int b,int a)
{
	int len=0;
	int mistakes=0;
	
	while(true)
	{
		if(a==0)
			break;
		
		int cur = b/a;
		len += cur;
		mistakes += cur-1;
		int t = b%a;
		b = a;
		a = t;		
	}
	
	if(b>1) return mp(-1,-1);	
	return mp(len,mistakes-1);
}

char c;
void construct(int a,int b)
{
	if(a==0) return;
	construct(b%a, a);
	
	if(a==1)
	{
		printf("T");
		for(int i=0;i<b-1;i++)
			printf("B");
		c='T';
		return;
	}
	
	int times = b/a;
	for(int i=0;i<times;i++)
		printf("%c",c);
	if(c=='T') c='B';
	else		c='T';
}


void solve()
{
	
	int best = INF;
	int besta = -1;
	for(int a=1;a<=r;a++)
	{
		//debug("SOlving",a,r);
		PII sol = get(r,a);
		if(sol.FF != n) continue;
		if(sol.SS < best)
		{
			best = sol.SS;
			besta = a;
		}
	}
	//debug("besta",besta);
	if(best==INF)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	
	if(r==1) best++;
	c='T';
	printf("%d\n",best);
	construct(besta,r);
}

bool input()
{
	s(n); s(r);
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