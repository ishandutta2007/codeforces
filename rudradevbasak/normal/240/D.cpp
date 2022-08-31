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
int a,b;
int sa[100005];
int sb[100005];

int ans[200005];
int arr[200005];

int cnt(int* arr,int n)
{
	int chng=0;
	for(int i=0;i+1<n;i++)
		if(arr[i]!=arr[i+1])
			chng++;
	if(arr[n-1]==1)
		chng++;
	return chng;
}


void solve()
{
	int ca = cnt(sa,a);
	int cb = cnt(sb,b);
	bool first = ca >= cb;
	
	int na=0,nb=0;
	int top=0;
	while(na<a && nb<b)
	{
		int z = first ? sa[na] : sb[nb];
		
		while(na<a && sa[na]==z)
		{
			ans[top] = na+1;
			arr[top] = z;
			top++;
			na++;
		}
		while(nb<b && sb[nb]==z)
		{
			ans[top] = a+nb+1;
			arr[top] = z;
			top++;
			nb++;
		}
	}
	
	while(na<a)
	{
		ans[top]=na+1;
		arr[top]=sa[na];
		top++;
		na++;
	}
	
	while(nb<b)
	{
		ans[top]=a+nb+1;
		arr[top]=sb[nb];
		top++;
		nb++;
	}
	
	int n=a+b;
	VI swaps;
	for(int i=0;i+1<n;i++)
	{
		if(arr[i]!=arr[i+1])
		swaps.pb(i+1);
	}
	if(arr[n-1]==1)
		swaps.pb(n);
	
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	
	printf("%d\n",swaps.size());
	for(int i=0;i<swaps.size();i++)
		printf("%d ",swaps[i]);
	printf("\n");
		
}

bool input()
{
	s(a);
	for(int i=0;i<a;i++)
		s(sa[i]);
	s(b);
	for(int i=0;i<b;i++)
		s(sb[i]);
	
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