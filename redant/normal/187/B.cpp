/* AnilKishore * India */

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

int d[61][61][61];
int D[61][61];
int M[61][61][61];
int n, m, rounds;
const int inf = (int)1e9;

int solve(int s,int t,int k)
{
	if(s==t) return 0;
	int &r = M[s][t][k];
	if(r!=-1) return r;
	r = D[s][t];
	if(k>0) REP(via,n) r = min(r,D[s][via]+solve(via,t,k-1));
	return r;
}

int main()
{
	n = SI; m = SI; rounds = SI;
	REP(k,m)
	{
		REP(i,n) REP(j,n) d[k][i][j] = SI;
		REP(p,n) REP(i,n) REP(j,n) d[k][i][j] = min(d[k][i][j],d[k][i][p]+d[k][p][j]);
	}
	REP(i,n) REP(j,n)
	{
		D[i][j] = inf;
		REP(k,m) D[i][j] = min(D[i][j],d[k][i][j]);
	}
	SET(M,-1);
	while(rounds--)
	{
		int s = SI-1, t = SI-1, k = SI;
		k = min(n,k);
		printf("%d\n",solve(s,t,k));
	}

	return 0;
}