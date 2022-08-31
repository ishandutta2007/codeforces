#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define s(n)	scanf("%d", &n);
#define sf(n)	scanf("%lf", &n);
#define ss(n)	scanf("%s", n);
#define all(v)	v.begin(),v.end()
#define FF		first
#define SS		second
#define tri(a,b,c)	mp(a,mp(b,c))
#define XX		first
#define YY		second.first
#define ZZ		second.second
#define fill(a,v)	memset(a,v,sizeof a)
#define INF		(int)1e9
#define	EPS		1e-9

#define debug(args...)	{dbg,args; cerr<<endl;}

struct debugger
{
	template <typename T>
	debugger & operator , (const T& v)
	{
		cerr << v << " ";
		return *this;
	}
} dbg;

void debugarr(int * a, int n)
{
	printf("[ ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("]\n");
}
	


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL>	VL;
typedef vector<PII> VII;
typedef vector<vector<int> > VVI;
typedef pair<int, pair<int,int> > TRI;


int testnum;
int n;
VI adj[5005];


VI sums[5005];
bool done[5005];


int dfs(int u)
{
	done[u]=true;
	int k=adj[u].size();
	int tot=1;
	for(int i=0;i<k;i++)
	{
		int v=adj[u][i];
		if(done[v]) continue;
		int z=dfs(v);
		
		sums[u].pb(z);
		tot+=z;
	}
	
	int left = n-tot;
	if(left>=0) sums[u].pb(left);
	return tot;
}

bool can[5005];

bool t1[5005];
bool t2[5005];

int calc(int u)
{
	fill(t1,false);
	t1[0]=true;
	
	int k=sums[u].size();
	for(int i=0;i<k;i++)
	{
		int z=sums[u][i];
		fill(t2,false);
		for(int j=0;j<=n;j++)
		{
			if(t1[j]) t2[j]=true;
			if(j>=z && t1[j-z]) t2[j]=true;
		}
		
		for(int j=0;j<=n;j++)
			t1[j]=t2[j];
	}
	
	for(int i=0;i<=n;i++)
		can[i] = can[i] || t1[i];
}



void solve()
{
	fill(done,false);
	dfs(0);
	
	fill(can,false);
	for(int i=0;i<n;i++)
		calc(i);
		
	int cnt=0;
	for(int i=1;i<=n-2;i++)
		if(can[i])
			cnt++;
			
	printf("%d\n",cnt);
	for(int i=1;i<=n-2;i++)
		if(can[i])
			printf("%d %d\n",i,n-1-i);
}

void input()
{
	s(n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		s(a); s(b);
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
}

int main()
{
	int T=1;
	for(int testnum=1;testnum<=T;testnum++)
	{
		input();
		solve();
	}
}