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

#define MX 200005

int pos[MX], A[MX], n;

int main()
{
	n = SI;
	REP(i,n) A[i] = SI;
	REP(i,n)
	{
		int x = SI;
		pos[x] = i;
	}
	int ans = 0;
	REP(i,n) if(i>0)
	{
		if(pos[A[i]]<pos[A[i-1]]){ ans = n-i; break; }
	}
	printf("%d\n",ans);
	
	return 0;
}