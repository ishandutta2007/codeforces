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
#define maX(a,b)				(a>b?a:b)
#define miN(a,b)				(a<b?a:b)
#define abS(x)					(x<0?-x:x)
#define FOR(i,a,b)				for(int i=a;i<b;i++)
#define REP(i,n)				FOR(i,0,n)
#define foreach(v,c)            for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
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
#define debug1(a)				cout<<(a)<<endl
#define debug2(a,b)				cout<<(a)<<" "<<(b)<<endl
#define debug3(a,b,c)			cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define debug4(a,b,c,d)			cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define debug5(a,b,c,d,e)		cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl

void sc(char &c){
	char temp[4];	ss(temp);	
	c=temp[0];
}

void debugvi(vector<int> arr,int n=INF){
	REP(i,min(SZ(arr),n)) printf("%d ",arr[i]);
	printf("\n");
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
const int base = 1<<14;
double sum[base+base];
double ok[base+base];
int n,m;
VII mush;
const int maxn=100005;
int a[maxn];
int h[maxn];
int l[maxn];
int r[maxn];



void preprocess()
{

}



void solve()
{

}

int lo,hi;

void update(int ind,int beg,int end,double p)
{
	if(beg>hi || end<lo) return;
	if(lo<=beg && end<=hi)
	{
		ok[ind]*=p;
		if(ind>=base)
		{
			sum[ind]=ok[ind]*mush[ind-base].SS;
			ind>>=1;
		}
		
		for( ; ind ; ind>>=1)
		{
			int twice = ind+ind;
			sum[ind] = ok[ind]*(sum[twice]+sum[twice+1]);	
		}
		return;
	}
	
	int mid = (beg+end)>>1;
	int twice = ind+ind;
	
	update(twice,beg,mid,p);
	update(twice+1,mid+1,end,p);
}

void update(int x,int y,double p)
{
	//debug3(x,y,p);
	lo=x;
	hi=y;
	update(1,0,base-1,p);
}


int indhi(int n)
{
	//debug1(upper_bound(all(mush),mp(n,INF))-mush.begin());
	return min(m-1,upper_bound(all(mush),mp(n,INF))-mush.begin()-1);
}

int indlo(int n)
{
	return max(0,lower_bound(all(mush),mp(n,-INF))-mush.begin());
}


bool input()
{
	s(n); s(m);
	for(int i=0;i<n;i++)
	{
		s(a[i]);
		s(h[i]);
		s(l[i]);
		s(r[i]);
	}
	
	mush.clear();
	int x,y;
	for(int i=0;i<m;i++)
	{
		s(x); s(y);
		mush.pb(mp(x,y));
	}
	
	sort(all(mush));
	for(int i=0;i<m;i++)
	{
		ok[base+i]=1.0;
		sum[base+i]=mush[i].SS;
	}
	
	for(int i=base-1;i;i--)
	{
		int twice = i+i;
		ok[i]=1.0;
		sum[i] = ok[i]*(sum[twice]+sum[twice+1]);
	}
	
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		double p;
		
		x=a[i]-h[i];
		y=a[i]-1;
		x=indlo(x);
		y=indhi(y);
		p=1-l[i]/100.0;
		if(x<=y)
			update(x,y,p);
			
		x=a[i]+1;
		y=a[i]+h[i];
		x=indlo(x);
		y=indhi(y);
		p=1-r[i]/100.0;
		if(x<=y)
			update(x,y,p);
	}
	
	
	printf("%.9lf\n",sum[1]);
		
		
	
	
	
	
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