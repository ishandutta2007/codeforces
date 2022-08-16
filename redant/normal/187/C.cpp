/* AnilKishore * India */

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
#define EACH(it,v) for(typeof((v).begin()) it = (v).begin();it!=(v).end();it++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

int n, m, k;
VI g[MX];
int minD[MX];
int D[MX];

bool solve(int s,int t,int R)
{
	if(R==0) return false;
	REP(i,n) D[i] = MX;
	queue<int> Q;
	Q.push(s);
	D[s] = 0;
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		EACH(it,g[u])
		{
			int v = *it, dv = D[u]+1;
			if(minD[v]==0) dv = 0;
			if(dv>=D[v]) continue;
			if(v==t) return true;
			D[v] = dv;
			if(dv<R) Q.push(v);
		}
	}
	return false;
}

int main()
{
	n = SI; m = SI; k = SI;
	REP(i,n) minD[i] = MX;
	queue<int> Q;
	REP(i,k){ int u = SI-1; minD[u] = 0; Q.push(u); }
	while(m--){ int u = SI-1, v = SI-1; g[u].PB(v); g[v].PB(u); }
	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		EACH(it,g[u])
		{
			int v= *it;
			if(minD[v]==MX){ minD[v] = 1 + minD[u]; Q.push(v); }
		}
	}
	int s = SI-1, t = SI-1;
	if(!solve(s,t,n)) puts("-1");
	else
	{
		int lo = 0, hi = n;
		while(hi-lo>1)
		{
			int md = (lo+hi)/2;
			if(solve(s,t,md)) hi = md;
			else lo = md;
		}
		printf("%d\n",hi);
	}
	return 0;
}