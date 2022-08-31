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
int N,M,K;
char a[1005],b[1005];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int get(char a,char b)
{
	if(a=='R' && b=='P') return 1;
	if(a=='P' && b=='S') return 1;
	if(a=='S' && b=='R') return 1;
	if(a=='P' && b=='R') return -1;
	if(a=='S' && b=='P') return -1;
	if(a=='R' && b=='S') return -1;
	return 0;
}

void solve()
{
	int l=M*K/gcd(M,K);
	int remcnt = N%l;
	int full = N/l;
	int cura=0,curb=0;
	int ansa=0,ansb=0;
	for(int i=0;i<l;i++)
	{
		char aa = a[i%M];
		char bb = b[i%K];
		
		int z=get(aa,bb);
		if(z>0) cura++;
		else if(z<0) curb++;
		
		if(i==remcnt-1)
		{
			ansa+=cura;
			ansb+=curb;
		}
	}
	ansa+=cura*full;
	ansb+=curb*full;
	printf("%d %d\n",ansa,ansb);
		
		
}

bool input()
{
	s(N);
	ss(a); ss(b);
	M=strlen(a);
	K=strlen(b);
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