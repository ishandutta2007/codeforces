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

#define MX 105

int a[MX];

int main()
{	
	int n = SI;
	REP(i,n) a[i] = SI;
	sort(a,a+n);
	int cnt = 0, pen = 0, ct = 10;
	REP(i,n)
	{
		if(ct+a[i]>720) break;
		ct+=a[i]; cnt++;
		if(ct>360) pen+=ct-360;
	}
	printf("%d %d\n",cnt,pen);
	return 0;
}