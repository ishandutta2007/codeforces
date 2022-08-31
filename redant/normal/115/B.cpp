/*
PROG: 
LANG: C++
ID: AnilKishore ( RedAnt )
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
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int((v).size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 205

int R, C;
char s[MX];
int mn[MX], mx[MX];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int R = SI, C = SI;
	REP(i,R)
	{
		scanf(" %s",s);
		mn[i]=MX; mx[i]=-1;
		REP(j,C) if(s[j]=='W') mn[i]=min(mn[i],j), mx[i]=max(mx[i],j);
	}
	
	int ans = 0;
	int x = 0, y = 0;
	REP(i,R)
	{
		if((i&1)==1 && mx[i]!=-1)
		{
			ans+=abs(y-mx[i])+i-x+mx[i]-mn[i];
			x=i; y=mn[i];
		}
		if((i&1)==0 && mx[i]!=-1)
		{
			ans+=abs(y-mn[i])+i-x+mx[i]-mn[i];
			x=i; y=mx[i];
		}
	}
	
	printf("%d\n",ans);
		
	return 0;
}