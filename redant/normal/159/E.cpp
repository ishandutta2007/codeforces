/*AnilKishore*India*/

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

int col[MX], sz[MX];
int ind[MX];

bool cmp(const int &i, const int &j)
{
	if(col[i]!=col[j]) return col[i]<col[j];
	return sz[j]<sz[i];
}

LL bestSz[MX], nextBestSz[MX];
int bestInd[MX], nextBestInd[MX];

void update(int cnt, LL sz,int index)
{
	if(sz>=bestSz[cnt])
	{
		nextBestSz[cnt] = bestSz[cnt];
		nextBestInd[cnt] = bestInd[cnt];
		bestSz[cnt] = sz;
		bestInd[cnt] = index;
	}
	else if(sz>nextBestSz[cnt])
	{
		nextBestSz[cnt] = sz;
		nextBestInd[cnt] = index;
	}
}

int bigCnt, smallCnt, bigIndex, smallIndex;
LL bestMaxSz;

void check(LL bigs, int bigi, int bigc, LL smalls, int smalli, int smallc)
{
	if(bigs==-1 || smalls==-1 || bigi==smalli) return;
	if(bigs+smalls > bestMaxSz)
	{
		bestMaxSz = bigs + smalls;
		bigIndex = bigi;
		smallIndex = smalli;
		bigCnt = bigc;
		smallCnt = smallc;
	}
}

void solve(int n)
{
	SET(bestSz,-1);
	SET(nextBestSz,-1);
	
	for(int i=0;i<n;)
	{
		LL sumsz = 0;
		int j = i;
		while(j<n && col[ind[i]]==col[ind[j]])
		{
			sumsz += sz[ind[j]];
			update(++j-i,sumsz,i);
		}
		i = j;
	}

	FOR(i,1,n+1)
	{
		check(bestSz[i],bestInd[i],i,nextBestSz[i],nextBestInd[i],i);
		if(i>1)
		{
			check(bestSz[i],bestInd[i],i,bestSz[i-1],bestInd[i-1],i-1);
			check(bestSz[i],bestInd[i],i,nextBestSz[i-1],nextBestInd[i-1],i-1);
		}
	}

	cout<<bestMaxSz<<endl;
	printf("%d\n",bigCnt+smallCnt);
	int bi = bigIndex, si = smallIndex;
	for(int i=0;i<min(bigCnt,smallCnt);i++)
		printf("%d %d ",ind[bi++]+1,ind[si++]+1);
	if(bigCnt>smallCnt)
		printf("%d",ind[bi]+1);
	puts("");
}

int main()
{
	int n = SI;
	REP(i,n)
	{
		col[i] = SI; sz[i] = SI;
		ind[i] = i;
	}
	sort(ind,ind+n,cmp);
	solve(n);
	return 0;
}