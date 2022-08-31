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

#define MXN 1000010

int at[MXN];
int n;
int a[MXN], b[MXN], p[MXN];

int lis()
{
	int u, v, k = 1;

	b[0] = 1;

	for(int i = 2; i <= n ; i++) 
	{
		if (a[b[k-1]] < a[i]) 
		{
			p[i] = b[k];
			b[k++] = i;
			continue;
		}

		for (u = 0, v = k-1; u < v;) 
		{
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}

		if (a[i] < a[b[u]]) 
		{
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}

	return k;
}


int main()
{
	n=SI;

	REP(i,n){ int x = SI; at[x] = i + 1; }

	REP(i,n)
	{
		int x = SI;
		a[n-i] = at[x];
	}

	printf("%d\n",lis());

	return 0;
}