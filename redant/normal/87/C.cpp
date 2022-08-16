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
#define FORE(i,v) for(__typeof((v).begin()) i = (v).begin(); i!=(v).end(); i++)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 100005
int g[MX], gx[MX];

int mex(VI &v)
{
	if(SZ(v)==0) return 0;
	sort(ALL(v));
	if(v[0]!=0) return 0;
	int i;
	for(i=1;i<SZ(v);i++)
		if(v[i]-v[i-1]>1) return v[i-1]+1;
	return v[i-1]+1;
}

int main()
{
	g[0]=g[1]=g[2]=0;

	int n = SI, r = -1;
	
	for(int i=3;i<=n;i++)
	{
		VI v;
		for(int k=2;(k*(k-1))/2<=i;k++)
		{
			int a = (i-(k*(k-1)/2))/k;
			if(a>=1 && k*a+(k*(k-1)/2)==i)
			{
				int b = a + k - 1;
				v.PB(gx[b]^gx[a-1]);
			}
		}
		g[i] = mex(v);
		gx[i]=gx[i-1]^g[i];
	}

	if(gx[n]!=0)
	{
		for(int k=2;(k*(k-1))/2<=n;k++)
		{
			int a = (n-(k*(k-1)/2))/k;
			if(a>=1 && k*a+(k*(k-1)/2)==n)
			{
				int b = a + k - 1;
				if((gx[b]^gx[a-1])==0){ r=k; break; }
			}
			if(r>-1) break;
		}
	}

	printf("%d\n",r);

	return 0;
}