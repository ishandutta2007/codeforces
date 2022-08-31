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
int n;
LL k;
int arr[100005];
VI nums;

const int BASE = 1<<17;
LL lt[BASE+BASE];
LL rt[BASE+BASE];

int lo,hi;
bool islt;
LL getsum(int ind,int beg,int end)
{
	if(beg>hi || end<lo) return 0;
	if(lo<=beg && end<=hi) return islt ? lt[ind] : rt[ind];
	int mid = (beg+end)>>1;
	int twice = ind+ind;
	return getsum(twice,beg,mid) + getsum(twice+1,mid+1,end);
}

LL insert(int u,bool islt,int add)
{
	int ind = u+BASE;
	if(islt)	lt[ind]+=add;
	else		rt[ind]+=add;
	
	for(ind>>=1; ind; ind>>=1)
	{
		if(islt)	lt[ind] = lt[ind+ind] + lt[ind+ind+1];
		else		rt[ind] = rt[ind+ind] + rt[ind+ind+1];
	}
}

LL countx(int _lo,int _hi,bool isleft)
{
	if(_lo>_hi) return 0;
	lo=_lo;
	hi=_hi;
	islt = isleft;
	return getsum(1,0,BASE-1);
}
		
LL getcount(int x)
{
	return countx(0,x-1,false) + countx(x+1,BASE-1,true);
}


void solve()
{
	LL ans=0;
	LL l=0;
	LL r=0;
	fill(lt,0);
	fill(rt,0);
	LL inv=0;
	
	for(int i=n-1;i>=0;i--)
	{
		inv += getcount(arr[i]);
		insert(arr[i], false, +1);
	}
	
	for(int i=0;i<n;i++)
	{
		if(r==i)
		{
			inv -= getcount(arr[r]);
			insert(arr[r], false, -1);
			r++;
		}
		inv += getcount(arr[i]);
		insert(arr[i], true, +1);

		while(inv>k && r<n)
		{
			inv -= getcount(arr[r]);
			insert(arr[r], false, -1);
			r++;
		}
		
		ans += n-r;
	}
	cout<<ans<<endl;
		
}

bool input()
{
	cin>>n>>k;
	nums.clear();
	for(int i=0;i<n;i++)
	{
		s(arr[i]);
		nums.pb(arr[i]);
	}
	DREP(nums);
	for(int i=0;i<n;i++)
		arr[i] = INDEX(nums,arr[i]);
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