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

#define MX 200005

char s[MX], ans[MX];
VI occ[27], del[27];
int bit[MX];

inline int Q(int x)
{
	int r = 0;
	for(;x;x-=x&-x) r+=bit[x];
	return r;
}

inline void U(int x)
{
	for(;x<MX;x+=x&-x) bit[x]++;
}

int get(int p)
{
	int lo = 0, hi = MX - 2;
	while(hi-lo>1)
	{
		int mid = (lo+hi)/2;
		int less = mid - Q(mid);
		if(less<p) lo = mid; else hi = mid;
	}
	return hi;
}

int main()
{
	int k;
	scanf("%d %s",&k,s);
	int n = strlen(s);
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
		{
			occ[s[j]-'a'].PB(n*i+j);
			ans[n*i+j] = s[j];
		}
	for(int nd=SI;nd--;)
	{
		int pos; char ch;
		scanf("%d %c",&pos,&ch);
		del[ch-'a'].PB(pos);
	}

	REP(i,26)
	{
		occ[i].PB(-1);
		SORT(occ[i]);
		SET(bit,0);
		EACH(it,del[i])
		{
			int pos = get(*it);
			ans[occ[i][pos]] = 0;
			U(pos);
		}
	}

	REP(i,n*k) if(ans[i]) printf("%c",ans[i]);
	puts("");

	return 0;
}