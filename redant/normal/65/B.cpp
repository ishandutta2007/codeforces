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

#define MX 1010

int n;
int gd[MX], bd[MX];
bool M[1001][1012];

bool doIt(int cp, int pd)
{
	if(cp>n) return true;
	if(M[cp][pd]) return false;
	M[cp][pd] = true;
	
	pd+=1000;
	
	int x = gd[cp];
	
	for(int p1=1,p2=10;p1<=10000;p1*=10,p2*=10)
	{
		int pre = (x/p2)*p2, suff = x%p1;
		for(int d=0;d<10;d++)
		{
			int y = pre + d * p1 + suff;	
			
			if(y>=pd && y>=1000 && y<=2011 && doIt(cp+1,y-1000) )
			{
				bd[cp]=y; return true;
			}
		}
	}
	
	return false;
}

int main()
{
	SET(M,false);
	
	n=SI;
	REP(i,n) gd[i+1]=SI;
	
	bool ok = doIt(1,0);
	
	if(!ok) puts("No solution");
	else
	{
		REP(i,n) printf("%d\n",bd[i+1]);
	}
	
	return 0;
}