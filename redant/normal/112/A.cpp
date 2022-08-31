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

#define MX 105

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	char a[MX], b[MX];
	scanf("%s %s",a,b);
	int n = strlen(a);
	REP(i,n)
	{
		int c1 = a[i]&(~32), c2 = b[i]&(~32);
		if(c1<c2){ puts("-1"); return 0; }
		if(c1>c2){ puts("1"); return 0; }
	}	
	puts("0");
	return 0;
}