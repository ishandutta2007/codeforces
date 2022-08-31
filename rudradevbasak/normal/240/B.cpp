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
int dp[205][40005][2];
int h[205];
int psum[205];
int a,b;
int n;

void solve()
{
	fill(dp,-1);
	dp[0][0][0]=0;
	dp[0][0][1]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<=psum[i];j++)
			for(int k=0;k<2;k++)
			{
				if(dp[i][j][k]<0) continue;
				int la = a-j;
				int lb = b-(psum[i]-j);
				
				int ht = h[i+1];
				
				//debug("dp",i,j,k,":",dp[i][j][k]);
				
				if(la>=ht)
				{
					int va = dp[i][j][k] + (k==1 ? min(h[i],h[i+1]) : 0);
					int & ans = dp[i+1][j+ht][0];
					if(ans<0 || (va<ans))
					{
						//debug(i+1,j+ht,0," : ", va);
						ans = va;
					}
				}
				
				if(lb>=ht)
				{
					int vb = dp[i][j][k] + (k==0 ? min(h[i],h[i+1]) : 0);
					int & ans = dp[i+1][j][1];
					if(ans<0 || vb<ans)
					{
						//debug(i+1,j,1," : ", vb);
						ans = vb;
					}
				}
			}
			
	int ans = INF;
	for(int j=0;j<=40000;j++)
		for(int k=0;k<2;k++)
			if(dp[n][j][k]>=0)
				ans = min(ans, dp[n][j][k]);
			
	if(ans == INF) ans=-1;
	printf("%d\n",ans);
				
			
		
		
}

bool input()
{
	s(n);
	s(a); s(b);
	psum[0]=0;
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		s(h[i]);
		psum[i] = psum[i-1]+h[i];
	}

	return true;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}