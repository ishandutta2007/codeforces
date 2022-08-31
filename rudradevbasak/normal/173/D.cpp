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
int N,M;
VI adjl[100005];
VI lt,rt;
int deg[100005];
VI drt,dlt;
bool done[100005];
int ans[100005];
bool temp[100005];

void dfs(int u,int dist)
{
	done[u]=true;
	if(dist)
	{
		rt.pb(u);
		drt.pb(deg[u]);
	}
	else
	{
		lt.pb(u);
		dlt.pb(deg[u]);
	}
	
	int k=adjl[u].size();
	for(int i=0;i<k;i++)
	{
		int v=adjl[u][i];
		if(!done[v])
			dfs(v,1-dist);
	}
}


void solve()
{
	fill(done,false);
	for(int i=0;i<N;i++)
		if(!done[i])
			dfs(i,0);
	int nr=rt.size(),nl=lt.size();
	fill(ans,-1);
	int k=1;
	
		
	if(nl%3==0 && nr%3==0)	//case 1 : easy!
	{
		//DO nothing :)		
	}
	else
	{	
		
		if(nl%3==2)
		{
			swap(lt,rt);
			swap(dlt,drt);
			swap(nl,nr);
		}
		
		//now left = 1 mod 3, right is 2 mod 3
		
			
		bool done=false;
		for(int i=0;i<nl;i++)
		{
			if(dlt[i]<=nr-2)
			{
				int src=lt[i];
				ans[src]=k;
				vector<bool> has(N,false);				
				for(int j=0;j<dlt[i];j++)
					has[adjl[src][j]]=true;
				int cnt=0;
				for(int j=0;j<nr;j++)
					if(!has[rt[j]])
					{
						ans[rt[j]]=k;
						cnt++;
						if(cnt==2) break;
					}
				k++;
				done=true;
				break;
			}
		}
		
		if(!done)
		{
			int misscnt=0;
			for(int i=0;i<nr;i++)
				if(drt[i]<=nl-2)
				{
					int src=rt[i];
					ans[src]=k;
					vector<bool> has(N,false);				
					for(int j=0;j<drt[i];j++)
						has[adjl[src][j]]=true;
					int cnt=0;
					for(int j=0;j<nl;j++)
						if(!has[lt[j]])
						{
							ans[lt[j]]=k;
							cnt++;
							if(cnt==2) break;
						}
					k++;
					misscnt++;
					if(misscnt==2)
					{
						done=true;
						break;
					}
				}
		}
		
		if(!done)
		{
			printf("NO\n");
			return;
		}
	}
	
	int kcnt=0;
	for(int i=0;i<rt.size();i++)
	{
		if(ans[rt[i]]<0)
		{
			ans[rt[i]]=k;
			kcnt++;
			if(kcnt==3)
			{
				k++;
				kcnt=0;
			}
		}
	}
	for(int i=0;i<lt.size();i++)
	{
		if(ans[lt[i]]<0)
		{
			ans[lt[i]]=k;
			kcnt++;
			if(kcnt==3)
			{
				k++;
				kcnt=0;
			}
		}
	}
		
	printf("YES\n");
	for(int i=0;i<N;i++)
		printf("%d ",ans[i]);
	printf("\n");
			
		
}

bool input()
{
	s(N); s(M);
	fill(deg,0);
	for(int i=0;i<M;i++)
	{
		int a,b;
		s(a); s(b);
		a--; b--;
		adjl[a].pb(b);
		adjl[b].pb(a);
		deg[a]++;
		deg[b]++;
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