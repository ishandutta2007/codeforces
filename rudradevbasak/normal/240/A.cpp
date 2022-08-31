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
int m,k;
int n;
bool isgood[105];
VI good;
VI bad;
VI actors[100];
int gc[100];
int bc[100];
int uc[100];
int ng;
int nb;
char temp[105];

int maxs[100];
int mins[100];

void solve()
{
	for(int i=0;i<n;i++)
	{
		int leftg = ng - gc[i];
		int leftb = nb - bc[i];
		maxs[i] = gc[i] + min( uc[i], leftg );
		mins[i] = (gc[i] + bc[i] + uc[i]) - ( bc[i] + min(uc[i], leftb) );
	}
	
	for(int i=0;i<n;i++)
	{
		bool defgood = true;
		bool defbad = false;
		for(int j=0;j<n;j++)
		{
			if(j==i) continue;
			if(maxs[j] > mins[i]) defgood = false;
			if(mins[j] > maxs[i]) defbad = true;
		}
		
		if(defgood) printf("0\n");
		else if(defbad) printf("1\n");
		else printf("2\n");
	}
		
}

bool input()
{
	s(m); s(k);
	fill(isgood,false);
	for(int i=0;i<k;i++)
	{
		int x; s(x);
		isgood[x]=true;
	}
	for(int i=1;i<=m;i++)
	{
		if(isgood[i])
			good.pb(i);
		else
			bad.pb(i);
	}
	ng = good.size();
	nb = bad.size();
	
	s(n);
	for(int i=0;i<n;i++)
	{
		ss(temp);
		int k; s(k);
		gc[i]=0;
		bc[i]=0;
		uc[i]=0;
		for(int j=0;j<k;j++)
		{
			int z; s(z);
			if(z==0) uc[i]++;
			else if(isgood[z]) gc[i]++;
			else bc[i]++;
		}
	}
	
	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}