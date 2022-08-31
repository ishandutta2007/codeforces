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
int n,m;
VI adj[1000005];
bool done[1000005];


int dfs(int u)
{
	done[u]=true;
	int k=adj[u].size();
	int ans = (k&1);
	for(int i=0;i<k;i++)
	{
		int v=adj[u][i];
		if(!done[v])
			ans += dfs(v);
	}
	return ans;
}





void solve()
{
	VI comps;
	fill(done,false);
	int sum=0;
	int full=0;
	
	for(int i=0;i<n;i++)
	{
		if(!done[i])
		{
			int ans = dfs(i);
			if(i==0 || adj[i].size()>0) comps.pb(ans);
			sum += ans;
			if(ans==0 && (i==0 || adj[i].size()>0)) full++;
		}
	}
	
	//debug(sum,full,comps.size());
	
	sum /= 2;
	if(comps.size() > 1)
		sum += full;
		
	cout<<sum<<endl;
	
}

void input()
{
	s(n); s(m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		s(a); s(b);
		a--; b--;
		//if(a==b) continue;
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