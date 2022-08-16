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

#define MX 100010

int n, m;
char S[MX], g[13][13];
int a[MX];

bool thr(int p,int k)
{
	for(int i=0;i<strlen(g[k]);i++)
		if(S[p+i]!=g[k][i]) return false;
	return true;
}

int bestlen(int p)
{
	int q = p + a[p] - 1;
	for(int i=p+1;i<q;i++) if(a[i]!=-1)
	{
		int qq = i + a[i] - 1;
		q = min(q,qq);
	}
	return q - p;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	scanf("%s",S);
	n=strlen(S);
	m=SI;
	REP(i,m) scanf(" %s",g[i]);
	
	SET(a,-1);
	
	REP(i,n)
	{
		int mn = MX;
		REP(j,m) if(thr(i,j)) mn=min(mn,(int)strlen(g[j]));
		if(mn<MX) a[i] = mn;
	}
	
	int len = 0, pos = 0;
		
	REP(i,n)
	{
		if(a[i]>0)
		{
			int clen = bestlen(i);
			if(clen>len) len=clen, pos=i;
		}
		else
		{
			int j = i + 1;
			while(j<n && a[j]==-1) j++;
			int clen = j - i;
			if(j<n) clen+=bestlen(j);
			if(clen>len) len=clen, pos=i;
			i=j;
		}
	}
	
	printf("%d %d\n",len,pos);
	
	return 0;
}