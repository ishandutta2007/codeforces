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

#define MX 100055

set<LL> S;

void go(LL x,int f4,int f7)
{
	if(f4>5 || f7>5) return;
	if(f4+f7>10) return;
	if(f4==f7) S.insert(x);
	go(x*10+4,f4+1,f7);
	go(x*10+7,f4,f7+1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	go(0,0,0);
	
	LL n = SI;
	
	LL r;
	
	if(S.count(n)) r = n;
	else r = *S.upper_bound(n);
	
	cout<<r<<endl;
	
	return 0;
}