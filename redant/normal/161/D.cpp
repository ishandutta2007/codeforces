/*AnilKishore*India*/

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

#define MXN 50001
#define MXK 501

int cnt[MXN][MXK];

int n, k;
VI g[MXN];
LL ans = 0;

void dfs1(int u,int pu)
{
	EACH(it,g[u]) if(*it!=pu) dfs1(*it,u);
	cnt[u][0] = 1;
	EACH(it,g[u]) if(*it!=pu) 
		for(int i=0;i<k;i++) cnt[u][i+1] += cnt[*it][i];
}

void dfs(int u,int pu)
{
	if(pu!=-1)
	{
		for(int i=k;i>1;i--)
			cnt[u][i] += cnt[pu][i-1] - cnt[u][i-2];
		cnt[u][1]++;
	}
	
	ans+=cnt[u][k];
	
	EACH(it,g[u]) if(*it!=pu) dfs(*it,u);
}

int main()
{
	n = SI; k = SI;
	REP(i,n-1)
	{
		int u = SI, v = SI;
		g[u].PB(v);
		g[v].PB(u);
	}
	if(k==1)
	{
		printf("%d\n",n-1);
		return 0;
	}
	dfs1(1,-1);
	dfs(1,-1);
	cout<<ans/2<<endl;
	return 0;
}