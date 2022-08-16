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

int getD(int x,int y,int n)
{
	if(x==0) return y;
	if(x==n) return 2*n+n-y;
	if(y==0) return 3*n+n-x;
	if(y==n) return n+x;
}

int main()
{
	int n = SI, x1 = SI, y1 = SI, x2 = SI, y2 = SI;
	int r = 0;

	int d1 = getD(x1,y1,n);
	int d2 = getD(x2,y2,n);

	r = abs(d1-d2);
	r = min( r , 4*n-r );

	cout<<r<<endl;

	return 0;
}