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

int main()
{	
	int n = SI, R = SI, r = SI;
	bool ok = true;

	if(r>R) { puts("NO"); return 0; }

	if(n==1) ok = true;
	else if(n==2) ok=(2*r<=R);
	else 
	{
		double th = asin((1.*r)/(1.*(R-r)));
		ok = (n*th) <= (M_PI+1e-9);
	}

	puts(ok?"YES":"NO");

	return 0;
}