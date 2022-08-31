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
#define EPS						1e-12
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
double l,v1,v2;
double arr[200005];
double lens[100005];

void preprocess()
{

}

void solve()
{
	double t = l/(v1+v2);
	double d = t*v2;
	
	int curs=0;
	double curb = 0;
	double cure = d;
	int beg=-1,end=-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=curb-EPS && arr[i]<cure-EPS)
		{
			curs++;
			if(beg==-1) beg=i;
			end=i;
		}
	}
	
	for(int i=0;i<=n;i++)
		lens[i]=0;
	//debug(curs,curb,cure,beg,end);	
	while(true)
	{
		double nb = beg==-1?INF+1:arr[beg];
		bool ok = arr[end+1]-d>=curb-EPS;
		double ne = ok ? arr[end+1]-d : nb+1;
		double nxt = min(nb,ne);
		if(nxt>l+l)
			nxt=l+l;
			
		lens[curs] += (nxt-curb);
		curb=nxt;
		cure=nxt+d;
		if(abs(nb-nxt)<EPS && ne>nxt+EPS)
		{
			curs--;
			beg++;
		}
		else if(abs(ne-nxt)<EPS && nb>nxt+EPS)
		{
			curs++;
			end++;
			if(beg==-1)
				beg=end;
		}
		else if(abs(nb-nxt)<EPS && abs(ne-nxt)<EPS)
		{
			beg++;
			end++;
		}
		//debug(curs,curb,cure,beg,end);
		if(abs(nxt-l-l)<EPS)
			break;
	}
	
	for(int i=0;i<=n;i++)
		printf("%.12lf\n",lens[i]/(l+l));
		
		
	
	
		
}



bool input()
{
	s(n); sf(l); sf(v1); sf(v2);
	for(int i=0;i<n;i++)
	{
		sf(arr[i]);
		arr[n+i]=l+l+arr[i];
	}
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