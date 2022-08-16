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

#define MX 200010
#define MOD 1000000007

PI b[MX];
int n, m, mx;
int B[MX];
PI s[2*MX];

int Q(int x)
{ 
	int r = 0; 
	for(;x;x-=x&-x){ r+=B[x]; if(r>=MOD) r-=MOD; }
	return r;
}

int S(int x,int y)
{
	int r = Q(y) - Q(x-1);
	if(r<0) r+=MOD;
	return r;
}

void U(int x,int v)
{
	for(;x<=mx+5;x+=x&-x){ B[x]+=v; if(B[x]>=MOD) B[x]-=MOD; }
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	n=SI; m=SI; int k=0;
	bool got0 = false, gotn = false;
	REP(i,m)
	{ 
		b[i].S=SI; b[i].F=SI;
		if(b[i].F==n) gotn=true;
		if(b[i].S==0) got0=true;
		s[k++]=MP(b[i].S,-i-1); 
		s[k++]=MP(b[i].F,i+1);
	}
	
	if(!got0 || !gotn){ puts("0"); return 0; }
		
	sort(s,s+k);
	mx = 1;
	for(int i=0;i<k;i++)
	{
		if(i>0 && s[i].F!=s[i-1].F) mx++;
		int ind = s[i].S;
		if(ind<0) b[-ind-1].S = mx;
		else b[ind-1].F = mx;
	}
	
	sort(b,b+m);
	
	U(1,1);
	REP(i,m)
	{
		int w = S(b[i].S,b[i].F-1);
		U(b[i].F,w);	
	}
	
	printf("%d\n",S(b[m-1].F,b[m-1].F));			
	
	return 0;
}