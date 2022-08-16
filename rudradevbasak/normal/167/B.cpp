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
int n,l,k;

double dp[205][205][605];
double p[205];
int a[205];
const int off = 300;

void preprocess()
{
	//........................................................................
}

int get(int k)
{
	k=max(-200,k);
	k=min(200,k);
	return k+off;
}

void solve()
{
	
	fill(dp,0);
	dp[0][0][get(k)]=1.0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=-200;k<=200;k++)
			{
				double val = dp[i][j][get(k)];
				//win
				if(a[i]==-1)
					dp[i+1][j+1][get(k-1)] += p[i] * val;
				else
					dp[i+1][j+1][get(k+a[i])] += p[i] * val;
				
				//lose
				dp[i+1][j][get(k)] += (1-p[i]) * val;
			}
			
	double ans=0;
	for(int j=l;j<=n;j++)
		for(int k=0;k<=200;k++)
			ans += dp[n][j][get(k)];
	printf("%.9lf\n",ans);
				
		
		//win
		
		
}



bool input()
{
	s(n); s(l); s(k);
	for(int i=0;i<n;i++)
	{
		int x; s(x);
		p[i]=x/100.0;
	}
	for(int i=0;i<n;i++)
		s(a[i]);
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