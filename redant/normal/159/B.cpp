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

#define MX 1005

VI marker[MX], cap[MX];
int mc[MX], cc[MX];

int main()
{
	int nmarkers = SI, ncaps = SI;
	while(nmarkers--)
	{
		int c = SI, d = SI;
		marker[d].PB(c);
	}
	while(ncaps--)
	{
		int c = SI, d = SI;
		cap[d].PB(c);
	}

	int tot = 0, beauty = 0;
	REP(i,MX)
	{
		tot += min(SZ(marker[i]),SZ(cap[i]));
		SET(mc,0);SET(cc,0);
		EACH(it,marker[i]) mc[*it]++;
		EACH(it,cap[i]) cc[*it]++;
		REP(j,MX) beauty += min(mc[j],cc[j]);
	}

	printf("%d %d\n",tot,beauty);

	return 0;
}