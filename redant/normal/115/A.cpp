/*
PROG: 
LANG: C++
ID: AnilKishore ( RedAnt )
 */

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
#define SZ(v) int((v).size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 2005

VI g[MX];

int get(int u)
{
	int r = 0;
	REP(i,g[u].size())
		r = max(r,get(g[u][i]));
	return r+1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int n = SI;
	VI boss;
	REP(i,n)
	{ 
		int x = SI - 1;
		if(x<0) boss.PB(i);
		else g[x].PB(i);
	}
	
	int ans = 0;
	REP(i,SZ(boss)) ans = max( ans, get(boss[i]) );
	
	printf("%d\n",ans);
		
	return 0;
}