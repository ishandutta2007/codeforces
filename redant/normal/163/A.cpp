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

#define MX 5005
#define MOD 1000000007

char s[MX], t[MX];
int M[MX][MX];

int get(int x,int y)
{
	if(x<0 || y<0) return 0;
	int &r = M[x][y];
	if(r!=-1) return r;
	r = get(x,y-1);
	if(s[x]==t[y])
	{
		r += 1 + get(x-1,y-1);
		if(r>=MOD) r-=MOD;
	}
	return r;
}

int main()
{
	scanf("%s %s",s,t);
	int sn = strlen(s), tn = strlen(t);
	SET(M,-1);
	int ans = 0;
	for(int i=0;i<sn;i++)
	{
		ans += get(i,tn-1);
		if(ans>=MOD) ans-=MOD;
	}
	printf("%d\n",ans);
	return 0;
}