//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
int N,M;
VVI adjList;
bool done[500];
int lvl[500];

int tot;

void dfs(int u,int l)
{
	done[u]=true;
	lvl[u]=l;
	int cnt=0;
	for(int i=0;i<adjList[u].size();i++)
	{
		int v=adjList[u][i];
		if(done[v])
		{
			if(lvl[v]<l) cnt++;
		}
			
		else dfs(v,l+1);
	}
	if(cnt>1) tot+= cnt-1;
}

void preprocess()
{

}

void solve()
{
	tot=0;
	fill(done,false);
	dfs(0,0);
	bool ok=true;
	for(int i=0;i<N;i++)
	{
		if(!done[i])
			ok=false;
	}
		
	
	if(tot!=1) ok=false;
	//if(M!=N) ok=false;
	if(ok)
		cout<<"FHTAGN!"<<endl;
	else
		cout<<"NO"<<endl;
}

bool input()
{
	s(N); s(M);
	adjList.clear();
	adjList.resize(N);
	for(int i=0;i<M;i++)
	{
		int x,y;
		s(x); s(y);
		x--; y--;
		adjList[x].pb(y);
		adjList[y].pb(x);
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