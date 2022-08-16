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
//#include<debugger>

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

#define M 1001
#define N 1001
VI adj[M];
bool done[N];
int lp[M],rp[N];

bool dfs(int u)
{
	int len=adj[u].size();
    for(int k=0;k<len;k++)
    {
		int v=adj[u][k];
        if(done[v]) continue;
        done[v]=true;
        if(rp[v]<0||dfs(rp[v]))
        {
            lp[u]=v; rp[v]=u;
            return true;
        }
    }
    return false;
}

int bpm(int m)
{
 	fill(lp,-1);
	fill(rp,-1);
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
        fill(done,false);
        if(dfs(i)) cnt++;
    }
	return cnt;
}


int R,C;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};

void preprocess()
{

}

void solve()
{
	int ans=0;
	if(R*C < 1000)
	{
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
			{
				if((i+j)&1) continue;
				for(int k=0;k<8;k++)
				{
					int x=i+dx[k];
					int y=j+dy[k];
					if(x<0 || x>=R || y<0 || y>=C) continue;
					adj[i*C+j].pb(x*C+y);
				}
			}
			ans= R*C-bpm(R*C);
	}
	else
	{
		if(C<R)
			swap(R,C);
			
		if(R==1)
			ans=C;
		else if(R==2)
		{
			if(C%4 == 1)
				ans=C+1;
			else
				ans=((C+3)/4)*4;
		}
		else ans = (R*C+1)/2;
	}
	
	
	
		
	cout<<ans<<endl;
		
}



bool input()
{
	s(R); s(C);
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