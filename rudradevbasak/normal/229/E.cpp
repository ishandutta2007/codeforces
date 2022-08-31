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
int wishes;
int n;
int sz[1000];
int fix[1000];
int var[1000];
int val[1000][1000];
int totalfix;
int totalvar;

double onerow[1005][1005];
double dp[1005][1005];

long double C[1005][1005];

VT goods;

void solve()
{
	fill(C,0);
	for(int i=0;i<=1000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	
	sort(all(goods));
	reverse(all(goods));
	
	fill(fix,0);
	fill(var,0);
	
	int thresh = goods[wishes-1].XX;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<sz[i];j++)
		{
			int z = val[i][j];
			if(z > thresh)
				fix[i]++;
			else if(z==thresh)
				var[i]++;
		}
		
	totalfix=0;
	totalvar=0;
	for(int i=0;i<n;i++)
	{
		totalfix += fix[i];
		totalvar += var[i];
	}
		
	for(int i=0;i<n;i++)
		for(int j=0;j<=wishes;j++)
		{
			if(j<fix[i])
				onerow[i][j] = 0;
			else if(j > fix[i] + var[i])
				onerow[i][j] = 0;
			else
				onerow[i][j] = C[var[i]][j-fix[i]] / C[sz[i]][j];
			
			//debug(i,j,onerow[i][j],"||||",fix[i],var[i]);
		}
	
	fill(dp,0);
	dp[0][0]=1;
	int varsum=0;
	int fixsum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=fix[i];j<=fix[i]+var[i];j++)
			for(int prev=fixsum;prev<=fixsum+varsum;prev++)
			{
				double p = C[var[i]][j-fix[i]] * C[varsum][prev-fixsum] / C[varsum + var[i]][ j-fix[i] + prev-fixsum ];
				dp[i+1][j+prev] += p * dp[i][prev] * onerow[i][j];
			}
		varsum += var[i];
		fixsum += fix[i];
	}
			
	printf("%.12lf\n",dp[n][wishes]);
	
		
}

bool input()
{
	s(wishes);
	s(n);
	for(int i=0;i<n;i++)
	{
		s(sz[i]);
		for(int j=0;j<sz[i];j++)
		{
			s(val[i][j]);
			goods.pb(tri(val[i][j],i,j));
		}
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