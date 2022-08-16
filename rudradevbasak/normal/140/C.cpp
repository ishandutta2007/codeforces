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
//#include<debugger>

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
#define debug(args...)			dbg(),args	
#define dline					cerr<<endl	

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

struct dbg
{
	template<typename T> dbg& operator , (const T& v)
	{	
		cerr<<v<<" ";	
		return *this;	
	}
	~dbg()   {cerr<<endl;}
};


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
int n;
VI arr;
int k;
VT trip;

map<int,int> cnt;
set<PII> heap;

void preprocess()
{

}

void solve()
{
	cnt.clear();
	for(int i=0;i<n;i++)
		cnt[arr[i]]--;
		
	foreach(x,cnt)
		heap.insert(mp((*x).SS,(*x).FF));
		
	int k=0;
	VT ans;
	
	while(true)
	{
		if(heap.size()<3) break;
		set<PII>::iterator it;
		
		it=heap.begin();
		int a = (*it).SS; int fa = (*it).FF;
		heap.erase(it);
		
		it=heap.begin();
		int b = (*it).SS; int fb = (*it).FF;
		heap.erase(it);
		
		it=heap.begin();
		int c = (*it).SS; int fc = (*it).FF;
		heap.erase(it);
		
		int x=min(a,min(b,c));
		int z=max(a,max(b,c));
		int y=a+b+c-x-z;
		
		ans.pb(tri(z,y,x));
		k++;
		
		fa++; fb++; fc++;
		
		if(fa<0) heap.insert(mp(fa,a));
		if(fb<0) heap.insert(mp(fb,b));
		if(fc<0) heap.insert(mp(fc,c));
	}
	
	printf("%d\n",k);
	for(int i=0;i<k;i++)
		printf("%d %d %d\n",ans[i].XX,ans[i].YY,ans[i].ZZ);
		
		
		
	
		
}

bool input()
{
	s(n);
	arr.resize(n);
	for(int i=0;i<n;i++)
		s(arr[i]);
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