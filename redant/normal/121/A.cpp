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

vector<LL> v;

void go(LL x)
{
	if(x>1e9) return;
	v.PB(x);
	go(x*10+4);
	go(x*10+7);
}

int main()
{
	LL a = SI, b = SI;
	go(4); go(7);
	v.PB(0);
	v.PB(4444444444ll);
	v.PB(4444444447ll);
	SORT(v);
	LL ans = 0;
	for(int i=1;v[i-1]<=b;i++)
		if(v[i]>=a) ans+=v[i]*(min(v[i],b)-max(a,v[i-1]+1)+1);
	cout<<ans<<endl;
	return 0;
}