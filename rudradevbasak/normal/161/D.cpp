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
const int MAXN = 50001;
int dp[MAXN][501];
LL ans;
VI adjl[MAXN];
int n,k;
bool done[MAXN];

void preprocess()
{

}

void dfs(int u)
{
	done[u]=true;
	int len=adjl[u].size();
	fill(dp[u],0);
	dp[u][0]++;
	
	VVI cnt;
	
	for(int i=0;i<len;i++)
	{
		int v=adjl[u][i];
		if(!done[v])
		{
			dfs(v);
			VI temp(k+1);
			for(int j=0;j+1<=k;j++)
			{
				dp[u][j+1]+=dp[v][j];
				temp[j+1]=dp[v][j];
			}
			cnt.pb(temp);
		}
	}
	
	int deg = cnt.size();
	ans += dp[u][k];
	for(int i=1;i<k-i;i++)
	{
		for(int j=0;j<deg;j++)
			ans += (LL)cnt[j][i] * (dp[u][k-i]-cnt[j][k-i]);
	}
	
	LL term=0;
	if(k%2 == 0)
		for(int j=0;j<deg;j++)
			term += (LL)cnt[j][k/2] * (dp[u][k/2] - cnt[j][k/2]);
			
	ans += term/2;
		
	//debugarr(dp[u],k+1);
	//debug(u,ans);
	
}

void solve()
{
	ans=0;
	fill(done,0);
	dfs(0);
	cout<<ans<<endl;
		
}



bool input()
{
	s(n); s(k);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		s(a); s(b);
		a--; b--;
		adjl[a].pb(b);
		adjl[b].pb(a);
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