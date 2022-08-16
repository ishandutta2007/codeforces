using namespace std;

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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define SI ({int x;scanf("%d",&x);x;})
#define SET(v,x) memset(v,x,sizeof v)

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define TC REP(kase,SI)

#define SZ(v) int(v.size())
#define PB(x) push_back(x)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))

#define MP(x,y) make_pair(x,y)
#define F first
#define S second

#define MX 1005

int n,mx,reg;
int p[MX], d[MX];
bool used[MX];
int tused[MX], ind[MX], curtime, tn = 0;

int main()
{
	int i,j,k,bi,bd;
	n=SI; mx=SI; reg=SI;
	for(i=1;i<=n;i++) p[i]=SI, d[i]=SI;

	int ch = mx, cd = 0; curtime = 0;
	
	for(k=1;k<=10000;k++)
	{
		// take damage & reg
		ch-=cd;
		ch=min(mx,ch+reg);

		// check health
		if(ch<=0) break;


		// choose spell
		bd=bi=-1;

		for(i=1;i<=n;i++)
		{
			if(used[i]) continue;
			if(ch*100>p[i]*mx) continue;
			if(d[i]>bd){ bd=d[i]; bi=i; }
		}

		if(bi!=-1)
		{ 
			cd+=bd; used[bi]=true; tused[tn]=curtime; ind[tn]=bi; tn++;
		}
		else
		{
			if(reg-cd>=0) break;
		}

		curtime++;
	}

	if(ch>0) printf("NO\n");
	else
	{
		printf("YES\n%d %d\n",curtime,tn);
		for(i=0;i<tn;i++) printf("%d %d\n",tused[i],ind[i]);
	}

	return 0;
}