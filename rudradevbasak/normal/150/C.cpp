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
const int BASE = 1<<18;
int n,m,c;
double arr[BASE];
double d[BASE];


struct data
{
	double sum;
	double best;
	double bestbeg;
	double bestend;
	
	data(double _sum=0, double _best=0, double _bestbeg=0, double _bestend=0)
	{
		sum=_sum;
		best=_best;
		bestbeg=_bestbeg;
		bestend=_bestend;
	}
};

data operator + (data a,data b)
{
	data ans;
	ans.sum = a.sum + b.sum;
	ans.best = max(a.bestend+b.bestbeg, max(a.best, b.best) );
	ans.bestbeg = max(a.bestbeg, a.sum+b.bestbeg);
	ans.bestend = max(b.bestend, a.bestend+b.sum);
	return ans;
}
	

data stree[BASE+BASE];

void preprocess()
{

}



void build()
{
	for(int i=0;i<BASE;i++)
	{
		double z=max(0.0,arr[i]);
		//debug(i,i+BASE);
		stree[i+BASE] = data(arr[i], z,z,z);
	}
	
	for(int i=BASE-1;i>0;i--)
	{
		stree[i] = stree[i+i] + stree[i+i+1];
	}
}

int lo,hi;
data query(int ind,int beg,int end)
{
	if(beg>hi || end<lo) return data(0,0,0,0);
	if(lo<=beg && end<=hi) return stree[ind];
	int twice = ind+ind;
	int mid = (beg+end)>>1;
	return query(twice,beg,mid) + query(twice+1,mid+1,end);
}

void solve()
{
	double ans=0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		s(a); s(b);
		lo=a;
		hi=b-1;
		data res = query(1,0,BASE-1);
		double cur = res.best;
		
		//debug(res.sum,res.best);
		ans += cur;
	}
	printf("%.12lf\n",ans);
		
}


bool input()
{
	s(n); s(m); s(c);
	int cur; s(cur);
	for(int i=1;i<n;i++)
	{
		int z; s(z);
		d[i] = z-cur;
		cur=z;
	}
	fill(arr,0);
	for(int i=1;i<n;i++)
	{
		double p; sf(p);
		p/=100.0;
		arr[i] = p*(-c) + d[i]/2.0;
	}
	
	build();
	
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