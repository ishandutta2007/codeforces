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
TRI lemm[100005];
int n,k,h;
int m[100005];
int v[100005];
int ind[100005];
int hs[100005];

void preprocess()
{

}

bool can(double t)
{
	for(int i=0;i<n;i++)
	{
		LL z = (LL)(v[i]*t);
		z = z/h;
		if(z>k) z=k;
		hs[i]=z;
	}
	
	int cur=1;
	for(int i=0;i<n;i++)
	{
		if(hs[i]>=cur)
		{
			cur++;
			if(cur==k+1) return true;
		}
	}
	return false;
}

VI get(double t)
{
	for(int i=0;i<n;i++)
	{
		LL z = (LL)(v[i]*t);
		z = z/h;
		if(z>k) z=k;
		hs[i]=z;
	}
	VI ans;
	int cur=1;
	for(int i=0;i<n;i++)
	{
		if(hs[i]>=cur)
		{
			cur++;
			ans.pb(ind[i]);
			if(cur==k+1) return ans;
		}
	}
	return ans;
}

void solve()
{
	double lo=0,hi=1e9;
	for(int iter=0;iter<100;iter++)
	{
		double mid=(lo+hi)/2;
		if(can(mid))
			hi=mid;
		else
			lo=mid;
	}
	
	VI ans = get(hi);
	for(int i=0;i<k;i++)
		printf("%d ",ans[i]+1);
	printf("\n");
		
}



bool input()
{
	s(n); s(k); s(h);
	for(int i=0;i<n;i++)
		s(m[i]);
	for(int i=0;i<n;i++)
		s(v[i]);
	for(int i=0;i<n;i++)
		lemm[i]=tri(m[i],v[i],i);
	sort(lemm,lemm+n);
	for(int i=0;i<n;i++)
	{
		m[i]=lemm[i].XX;
		v[i]=lemm[i].YY;
		ind[i]=lemm[i].ZZ;
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