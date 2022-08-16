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

#define MX 2010

int n,h;
char s[MX];

int main()
{
	int i,j,r=MX,rr;

	n=SI;
	scanf(" %s",s);
	for(i=n;i<2*n;i++) s[i]=s[i-n];
	for(i=0;i<n;i++) if(s[i]=='H') h++;

	rr=0;
	for(i=0;i<h;i++) if(s[i]!='H') rr++;
	r=rr;
	
	for(i=1;i<n;i++)
	{
		if(s[i-1]=='T') rr--;
		if(s[i+h-1]=='T') rr++;
		r=min(rr,r);
	}

	printf("%d\n",r);

	return 0;
}