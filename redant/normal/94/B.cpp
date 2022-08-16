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

#define MX 100005

int g[6][6];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int m = SI;
	REP(i,m){ int a=SI,b=SI; g[a][b]=g[b][a]=1; }
	int win = 0;
	
	FOR(i,1,6) FOR(j,i+1,6) FOR(k,j+1,6)
		win|=(g[i][j]&&g[i][k]&&g[j][k])||((!g[i][j])&&(!g[i][k])&&(!g[j][k]));
	
	puts(win?"WIN":"FAIL");
	
	return 0;
}