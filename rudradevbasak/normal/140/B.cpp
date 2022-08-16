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
int pref[305];
int arr[305][305];
int ans[305];
int tm[305];

void preprocess()
{

}

int index(int k)
{
	for(int i=1;i<=n;i++)
		if(pref[i]==k)
			return i;
}

int index(int k,int ind)
{
	for(int i=1;i<=n;i++)
		if(arr[ind][i]==k)
			return i;
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		ans[i]=INF;
		tm[i]=INF;
	}
		
	int best=INF,best2=INF;
	for(int i=1;i<=n;i++)
	{
		int pos=index(i);
		if(pos<best) 
		{
			best2=best;
			best=pos;
		}	
		else if(pos<best2)
			best2=pos;
			
		for(int j=1;j<=n;j++)
		{
			int send=-1;
			if(best<INF && pref[best]!=j)
				send = pref[best];
			else if(best2<INF && pref[best2]!=j)
				send = pref[best2];
				
			if(send==-1) continue;
			
			if(index(send,j) < ans[j])
			{
				ans[j] = index(send,j);
				tm[j] = i;
			}
		}
	}
		
	for(int i=1;i<=n;i++)
		printf("%d ",tm[i]);
				
		
		
}

bool input()
{
	s(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s(arr[i+1][j+1]);
			
	for(int i=0;i<n;i++)
		s(pref[i+1]);
		
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