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
int n,k;
int age[100005];
int low[100005];
int high[100005];
int resp[100005];
int best[100005];
VI ages;
int ans[100005];

const int BASE=1<<19;
int stree[BASE+BASE];

void fillWith(int val)
{
	for(int i=0;i<BASE+BASE;i++)
		stree[i] = val;
}

void updatesum(int ind)
{
	ind+=BASE;
	stree[ind]++;
	for(ind>>=1; ind ; ind>>=1)
		stree[ind] = stree[ind+ind] + stree[ind+ind+1];
}

void updatemax(int ind,int val)
{
	ind+=BASE;
	stree[ind]=max(stree[ind],val);
	for(ind>>=1; ind ; ind>>=1)
		stree[ind] = max(stree[ind+ind],stree[ind+ind+1]);
}

int lo,hi;
int getsum(int ind,int beg,int end)
{
	if(beg>hi || end<lo) return 0;
	if(lo<=beg && end<=hi) return stree[ind];
	
	int twice = ind+ind;
	int mid=(beg+end)>>1;
	return getsum(twice,beg,mid) + getsum(twice+1,mid+1,end);
}
int getmax(int ind,int beg,int end)
{
	if(beg>hi || end<lo) return -INF;
	if(lo<=beg && end<=hi) return stree[ind];
	
	int twice = ind+ind;
	int mid=(beg+end)>>1;
	return max(getmax(twice,beg,mid) , getmax(twice+1,mid+1,end));
}
VT ppl;

vector<pair<PII,PII> > queries;

void solve()
{
	sort(all(ppl));
	fillWith(0);
	for(int i=0;i<n;i++)
	{
		int j=i;
		while(j<n && ppl[j].XX==ppl[i].XX)
			j++;
			
		for(int k=i;k<j;k++)
			updatesum(ppl[k].YY);
			
		for(int k=i;k<j;k++)
		{
			int ind = ppl[k].ZZ;
			lo=low[ind];
			hi=high[ind];
			best[k] = getsum(1,0,BASE-1);
		}
		i=j-1;
	}
	
	int q; s(q);
	for(int i=0;i<q;i++)
	{
		int x,y;
		s(x); s(y);
		x--; y--;	
		queries.pb(mp( mp(max(resp[x],resp[y]), i), mp(max(low[x],low[y]), min(high[x],high[y])) ) );
	}
	
	sort(all(queries));
	fillWith(-1);
	int cur = n-1;
	for(int i=q-1;i>=0;i--)
	{
		int curresp = queries[i].FF.FF;	
		while(cur>=0 && ppl[cur].XX >= curresp)
		{
			updatemax(ppl[cur].YY, best[cur]);
			cur--;
		}
		int ind=queries[i].FF.SS;
		lo=queries[i].SS.FF;
		hi=queries[i].SS.SS;
		if(lo>hi) ans[ind]=-1;
		else ans[ind]=getmax(1,0,BASE-1);
	}
	
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
		
}

bool input()
{
	s(n); s(k);
	for(int i=0;i<n;i++)
		s(resp[i]);
	for(int i=0;i<n;i++)
	{
		s(age[i]);
		ages.pb(age[i]);
		ages.pb(age[i]+k);
		ages.pb(age[i]-k);
	}
	DREP(ages);
	for(int i=0;i<n;i++)
	{
		
		low[i]=INDEX(ages,age[i]-k);
		high[i]=INDEX(ages,age[i]+k);
		age[i]=INDEX(ages,age[i]);
		ppl.pb(tri(resp[i],age[i],i));
		
	}
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