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

#define MX 101010

int g[101][101];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t = SI, ans = 0;
	while(t--)
	{
		int n = SI;
		REP(i,n){ REP(j,n) g[i][j] = MX; g[i][i]=0; }
		for(int m=n-1;m--;)
		{
			int a = SI, b = SI;
			a--; b--;
			g[a][b] = g[b][a] = 1;
		}
		REP(k,n) REP(i,n) REP(j,n)
			g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
		int mx = 0;
		REP(i,n) REP(j,n) if(g[i][j]<MX) mx = max(mx,g[i][j]);
		ans+=mx;
	}

	printf("%d\n",ans);

	return 0;
}