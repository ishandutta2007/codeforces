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

#define MX 100005

int n, m, x, y;
int a[MX], b[MX], indV[MX];
int sol[MX], indS[MX];
vector<PI> ans;

bool cmps(const int &i, const int &j)
{
	return sol[i] < sol[j];
}

bool cmpv(const int &i, const int &j)
{
	if(b[i]!=b[j]) return b[i]<b[j];
	return a[i]<a[j];
}

int main()
{
	n = SI; m = SI; x = SI; y = SI;
	REP(i,n){ sol[i] = SI; indS[i] = i; }
	REP(i,m){ int z = SI; a[i] = z-y; b[i] = z+x; indV[i] = i; }
	sort(indS,indS+n,cmps);
	sort(indV,indV+m,cmpv);
	for(int si = 0, vi = 0;si<n;si++)
	{
		int ss = sol[indS[si]];
		while(vi<m && b[indV[vi]]<ss) vi++;
		if(vi<m && a[indV[vi]]<=ss && ss <= b[indV[vi]])
		{
			ans.PB(MP(indS[si],indV[vi]));
			vi++;
		}
	}
	printf("%d\n",SZ(ans));
	EACH(it,ans)
	{
		printf("%d %d\n",(it->first)+1,(it->second)+1);
	}
	return 0;
}