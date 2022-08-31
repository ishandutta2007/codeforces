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
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MXN 50005

VI g[MXN];
int n,r1,r2,P[MXN];

void dfs(int u,int pu)
{
	for(int i=0;i<SZ(g[u]);i++)
	{
		int v = g[u][i];
		if(v==pu) continue;
		P[v]=u;
		dfs(v,u);
	}
}

int main()
{
	int i,j,k,u,v;
	n=SI; r1=SI; r2=SI;
	
	for(i=1;i<=n;i++)
	{
	 	if(i==r1) continue;
		u = SI;
		g[u].PB(i); g[i].PB(u);
	}

	dfs(r2,-1);

	for(i=1;i<=n;i++)
		if(i!=r2) printf("%d ",P[i]);
	puts("");

	return 0;
}