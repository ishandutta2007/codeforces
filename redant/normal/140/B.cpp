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

#define MX 303

int A[MX], B[MX], F[MX][MX], n;

int main()
{	
	n = SI;
	REP(i,n) REP(j,n) F[i][j] = SI;
	REP(i,n) A[SI] = i+1;
	REP(i,n)
	{
		REP(j,n) B[F[i][j]] = j+1;
		int psf = MX, b = -1;
		FOR(k,1,n+1)
		{
			if(k==i+1) continue;
			if(b==-1 || (A[k]<psf && B[k]<B[b])) b=k;
			psf=min(psf,A[k]);
		}
		printf("%d ",b);	
	}
	puts("");
	return 0;
}