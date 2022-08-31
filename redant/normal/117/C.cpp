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
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,(v).begin(),(v).end())
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 5001

int n;
char s[MX][MX];

bool solve(vector<int> &v)
{
	if(SZ(v)<3) return false;
	VI v1, v2;
	EACH(i,v) if(s[*i][v[0]]=='1') v2.PB(*i);
	EACH(i,v) if(s[v[0]][*i]=='1')
	{
		v1.PB(*i);
		EACH(j,v2) if(s[*i][*j]=='1')
		{
			printf("%d %d %d\n",v[0]+1,*i+1,*j+1);
			return true;
		}
	}
	if(solve(v1)) return true;
	if(solve(v2)) return true;
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	n = SI;
	REP(i,n) scanf(" %s",s[i]);
	VI v;
	REP(i,n) v.PB(i);
	if(!solve(v)) puts("-1");
		
	return 0;
}