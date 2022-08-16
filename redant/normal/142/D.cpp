/* ID: AnilKishore ( RedAnt ) */

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

#define MX 105



int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	char t[MX];
	VI nims;
	bool gAlone = false, rAlone = false, win = false;
	int n = SI, m = SI, k = SI;
	REP(i,n)
	{
		scanf(" %s",t);
		int posG = -1, posR = -1, posDash = -1;
		REP(j,m) if(t[j]=='G') posG = j; else if(t[j]=='R') posR = j; else if(t[j]=='-') posDash = j;
		if(posG!=-1 && posR==-1 && posDash!=-1) gAlone = true;
		if(posR!=-1 && posG==-1 && posDash!=-1) rAlone = true;
		if(posG!=-1 && posR!=-1) nims.PB(abs(posG-posR)-1);
	}
	
	if(gAlone)
	{
		if(rAlone){ puts("Draw"); return 0; }
		else { puts("First"); return 0; }
	}
	else if(rAlone){ puts("Second"); return 0; }

	REP(i,10)
	{
		int cnt = 0;
		EACH(it,nims) if((*it>>i)&1) cnt++;
		if(cnt%(k+1)!=0) win = true;
	}
	
	puts(win?"First":"Second");
			
	return 0;
}