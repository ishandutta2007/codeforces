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

int ans = 0;
LL lim;
LL f[16];

void go(LL x)
{
	if(x>lim) return;
	ans++;
	go(x*10+4);
	go(x*10+7);
}

void get(VI &v,int x,LL k)
{
	if(k==0) return;
	int y = x, i = SZ(v)-x-1;
	while(f[i]<=k) k-=f[i], y++;
	swap(v[x],v[y]);
	for(int j=y-1;j>x;j--) swap(v[j],v[j+1]);
	get(v,x+1,k);
}

bool isLucky(LL x)
{
	while(x) if(x%10!=4 && x%10!=7) return false; else x/=10;
	return true;
}

int main()
{
	f[0]=1;
	REP(i,14) f[i+1]=(i+1)*f[i];
	
	LL n = SI, k = SI;
	
	LL m = 1, s = 1;
	while(f[m]<k) m++;

	if(m>n){ puts("-1"); return 0; }
	lim = n-m;
	go(4); go(7);
	VI v;
	REP(i,m) v.PB(i+1);
	get(v,0,k-1);
	REP(i,m) if(isLucky(lim+i+1) && isLucky(lim+v[i])) ans++;
	cout<<ans<<endl;
	return 0;
}