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
int arr[5005];
int psum[5005];
int dp[5005][5005];

int getsum(int i,int j)
{
	return psum[j+1] - psum[i];
}

int getbest(int last,int maxht)
{
	int pos = (int)(lower_bound(psum, psum+n, psum[last+1]-maxht) - psum);
	if(pos==last+1)
		return -1;
	return pos;
}

void solve()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dp[i][j]=INF;
	
	for(int i=0;i<n;i++)
		dp[i][0] = i;
		
	for(int i=0;i<n;i++)
	{
		for(int j=i; j>=1; j--)
		{
			int curht = getsum(j,i);
			int ind = getbest(j-1, curht);
			if(ind<0) continue;
			dp[i][j] = dp[j-1][ind] + (i-j);
		}
		
		for(int j=i-1;j>=0;j--)
			dp[i][j] = min(dp[i][j], dp[i][j+1]);
	}
	
	int ans=INF;
	for(int i=0;i<n;i++)
		ans = min(ans, dp[n-1][i]);
		
	printf("%d\n",ans);
		
}

bool input()
{
	s(n);
	for(int i=0;i<n;i++)
		s(arr[i]);
	psum[0]=0;
	for(int i=0;i<n;i++)
		psum[i+1] = psum[i]+arr[i];
		
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