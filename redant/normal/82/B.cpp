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

VI a[MX], r[MX];
int ind1[222], ind2[222];
bool done[222];
int cur[222];

int main()
{
	int n = SI, m = (n*(n-1))/2;
	
	SET(ind1,-1); SET(ind2,-1);

	REP(i,m)
	{
		int k=SI; 

		REP(j,k)
		{
			int x = SI;
			a[i].PB(x);
			if(ind1[x]==-1) ind1[x]=i;
			else if(ind2[x]==-1) ind2[x]=i;
		}
	}

	if(n==2)
	{
		printf("1 %d\n",a[0][0]);
		printf("%d",SZ(a[0])-1);
		FOR(i,1,SZ(a[0])) printf(" %d",a[0][i]);
		puts("");
		return 0;
	}

	int p = 0;

	REP(i,222)
	{
		if(ind1[i]==-1 || done[i]) continue;
		//printf("--> %d @ %d,%d\n",i,ind1[i],ind2[i]);
		SET(cur,0);
		int j = ind1[i];
		REP(k,SZ(a[j])) cur[a[j][k]]++;
		j = ind2[i];
		REP(k,SZ(a[j])) cur[a[j][k]]++;
		REP(k,222)
		{
			if(cur[k]==2){ r[p].PB(k); done[k]=true; }
		}
		p++;
	}

	REP(i,p)
	{
		printf("%d ",SZ(r[i]));
		REP(j,SZ(r[i])) printf(" %d",r[i][j]);
		puts("");
	}

	return 0;
}