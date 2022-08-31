/* AnilKishore ( RedAnt ) */

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
#define FORE(i,v) for(__typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005

int main()
{

	LL d,m;
	cin>>d>>m;
	LL g = __gcd(d,m);
	g=(d/g)*m;

	LL fd = g/d - 1;
	LL fm = g/m - 1;

	if(d>m) fd++; else fm++;

	puts( (fd>fm) ? "Dasha" : (fd<fm ? "Masha" : "Equal") );

	return 0;
}