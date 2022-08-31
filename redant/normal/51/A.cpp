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

#define MX 111
#define MXN 100005

set<int> S;

int id(int x)
{
	int mn = x;
	for(int i=0;i<3;i++)
	{
		int d = x%10; x/=10; x+=d*1000;
		mn=min(x,mn);
	}
	return mn;
}

int main()
{
	int t=SI; char s[5];
	
	while(t--)
	{
		int a,b;
		a=SI; b=SI; scanf(" %s",s);
		a = a*100 + (b%10)*10 + (b/10);
		S.insert(id(a));
	}

	printf("%d\n",S.size());

	return 0;
}