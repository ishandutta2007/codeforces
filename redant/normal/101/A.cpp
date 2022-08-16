/* AnilKishore ( RedAnt ) */

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

#define MX 100005

PI f[26];
char s[MX];
bool rem[26];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int k;
	scanf("%s %d",s,&k);
	int n = strlen(s);
	REP(i,n) f[s[i]-'a'].F++;
	REP(i,26) f[i].S=i;
	sort(f,f+26);
	int m = 0;
	REP(i,26) if(f[i].F) m++;
	REP(i,26) if(f[i].F)
		if(f[i].F<=k)
		{ 
			k-=f[i].F; rem[f[i].S]=true;  
			m--;
		}
	printf("%d\n",m);
	REP(i,n) if(!rem[s[i]-'a']) printf("%c",s[i]);
	puts("");
	
	return 0;
}