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
char str[105];
LL dp[3005][105];
const LL mod = 1000000007;

void preprocess()
{
	fill(dp,0);
	for(int i=0;i<3005;i++)
		dp[i][0]=1;
	for(int i=1;i<3000;i++)
		for(int j=1;j<=i && j<=100;j++)
			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]) % mod;
		
}

LL get(int k,int n)
{
	if(k<0) return 0;
	return dp[k+n-1][n-1];
}

void solve()
{
	int n=strlen(str);
	int k=0;
	for(int i=0;i<n;i++)
		k+=str[i]-'a';
		
	LL ans=mod-1;
	for(int i=0;i<=n;i++)
	{
		LL term = (dp[n][i] * get(k-26*i,n))%mod;
		//debug(k,n,i,dp[n][i],get(k-26*i,n));
		if(i&1)
			ans = (ans + mod - term) % mod;
		else
			ans = (ans + term) % mod;
	}
	
	//cout<<(int)ans<<endl;
	printf("%d\n",(int)ans);
		
}




bool input()
{
	ss(str);
	return true;
}


int main()
{
	preprocess();
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		input();
		solve();
	}
}