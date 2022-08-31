/* 
 Team : AntiThesis 
 Members : lucyfer, RedAnt
 */


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

#define MX 1003

int a[MX];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n = SI, k = SI;
	REP(i,n) a[i]=SI;
	int r = k-1;
	while(1)
	{
		if(a[r]==1) break;
		r=(r+1)%n;
	}
	printf("%d\n",r+1);

	return 0;
}