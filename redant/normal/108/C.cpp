#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 1005
#define inf 1000000000

vector<PI> g[MX];
bool vis[MX];
vector<pair<int,PI> > ans;
VI S;
int ind[MX];

int st, en, dm;

void dfs(int x)
{
	vis[x]=true;
	if(dm!=inf && x==st){ dm=inf; return; }
	if(SZ(g[x])==0){ en=x; return; }
	dm=min(dm,g[x][0].S);
	dfs(g[x][0].F);
}

int main()
{
	int n=SI, p=SI;
	
	REP(i,p)
	{
		int a = SI, b = SI, d = SI;
		g[a].PB(MP(b,d));
		ind[b]=1;
	}

	REP(i,n)
	{
		if(ind[i+1]) continue;
		st = i+1; dm = inf;
		if(SZ(g[st])>0 && !vis[st]) dfs(st);
		if(dm<inf) ans.PB(MP(st,MP(en,dm)));
	}

	printf("%d\n",SZ(ans));
	REP(i,SZ(ans)) printf("%d %d %d\n",ans[i].F,ans[i].S.F,ans[i].S.S);

	return 0;
}