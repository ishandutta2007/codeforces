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

#define MX 20004
#define inf 1123456789

int n, r;
int a[MX], b[MX];

void check(int L)
{
	if(n/L<3) return;
	REP(i,L) b[i] = 0;
	REP(i,n) b[i%L]+=a[i];
	int best = b[0];
	REP(i,L) best = max(best,b[i]);
	r = max(r,best);
}

int main()
{
	n = SI;
	REP(i,n) a[i] = SI;
	r = -inf;
	for(int i=1;i*i<=n;i++) if(n%i==0) check(i), check(n/i);
	printf("%d\n",r);
	return 0;
}