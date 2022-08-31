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
int k,n;
VII stool;
VII other;
double ans;
VVI carts;

void preprocess()
{

}

void solve()
{
	sort(all(stool),greater<pair<int,int> >());
	int a=stool.size();
	carts.resize(k);
	ans=0;
	if(a>=k-1)
	{
		for(int i=0;i<k-1;i++)
		{
			carts[i].pb(stool[i].SS);
			ans += stool[i].FF/2.0;
		}
		
		double last=0;
		double least = INF+1;
		for(int i=k-1;i<a;i++)
		{
			carts[k-1].pb(stool[i].SS);
			last += stool[i].FF;
			least = min(least,(double)stool[i].FF);
		}
		for(int i=0;i<other.size();i++)
		{
			carts[k-1].pb(other[i].SS);
			last += other[i].FF;
			least = min(least,(double)other[i].FF);
		}
		
		if(a>=k)
			last = last - least/2.0;
		ans+=last;
	}
	else
	{
		for(int i=0;i<a;i++)
		{
			carts[i].pb(stool[i].SS);
			ans += stool[i].FF/2.0;
		}
		
		for(int i=0;i<k-1-a;i++)
		{
			carts[a+i].pb(other[i].SS);
			ans += other[i].FF;
		}
		
		for(int i=k-1-a;i<other.size();i++)
		{
			carts[k-1].pb(other[i].SS);
			ans += other[i].FF;
		}
	}
	
	printf("%.1f\n",ans);
	for(int i=0;i<k;i++)
	{
		printf("%d",carts[i].size());
		for(int j=0;j<carts[i].size();j++)
			printf(" %d",carts[i][j]);
		printf("\n");
	}
		
		
}



bool input()
{
	s(n); s(k);
	for(int i=0;i<n;i++)
	{
		int a,b;
		s(a); s(b);
		if(b==1)
			stool.pb(mp(a,i+1));
		else
			other.pb(mp(a,i+1));
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