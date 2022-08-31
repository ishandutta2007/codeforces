/*
LANG: C++
ID: AnilKishore
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)

const int mxn = 2005;
const LL inf = 100000000ll*100000000ll;
int n,m,k;
int c[mxn], t[mxn];
LL memo[mxn][mxn];

LL get( int ci, int items)
{
	if(items>=n) return 0;
	if(ci==n) return inf;
	LL &r = memo[ci][items];
	if(r!=-1) return r;
	return r = min( get( ci+1 , items ) , c[ci] + get( ci+1 , items+1+t[ci] )  );
}

int main()
{
	int i,j;

	SI(n);
	for(i=0;i<n;i++)
	{
		SI(t[i]); SI(c[i]);
	}

	SET(memo,-1);

	cout<< get(0,0) <<endl;

	return 0;
}