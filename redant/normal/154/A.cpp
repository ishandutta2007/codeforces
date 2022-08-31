/* RedAnt */

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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	char s[MX], g[3];
	int f[256];
	int n, ans = 0;
	
	scanf("%s %d",s,&n);
	while(n--)
	{
		scanf(" %s",g);
		f[g[0]] = g[1];
		f[g[1]] = g[0];
	}
	
	for(int i=0;i<strlen(s);)
	{
		int j = i, c1 = 0, c2 = 0;
		while(j<strlen(s) && ( s[j]==s[i] || s[j]==f[s[i]] ) )
		{
			if(s[j]==s[i]) c1++; else c2++;
			j++;
		}
		ans += min(c1,c2);
		i = j;
	}
	
	printf("%d\n",ans);
		
	return 0;
}