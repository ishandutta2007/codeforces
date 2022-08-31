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

#define MX 100005

int N, K, H;
pair<PI,int> A[MX];

bool ok(double t)
{
	int h = K*H, i = N-1;
	for(int i=N-1;i>=0 && h>0;i--)
	{
		int v = A[i].F.S;
		if(h<=v*t) h-=H;
	}
	return h == 0;
}

int main()
{
	N = SI; K = SI; H = SI;
	REP(i,N)  A[i].F.F = SI;
	REP(i,N){ A[i].F.S = SI; A[i].S=i; }
	sort(A,A+N);
	double lo = 0.0, hi = 1e10;
	REP(i,200){ double md = (lo+hi)/2; if(ok(md)) hi=md; else lo=md; }
	double t = hi; //(lo+hi)/2;
	VI ans;
	for(int h=K*H,i=N-1;i>=0 && h>0;i--)
	{
		int v = A[i].F.S;
		if(h<=v*t){ h-=H; ans.PB(A[i].S+1); }
	}
	//printf("t = %lf\n",t);
	reverse(ALL(ans));
	EACH(it,ans) printf("%d ",*it);
	puts("");
	return 0;
}