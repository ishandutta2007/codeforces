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
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define ABS(x) ((x)<0?(-1*(x)):(x))
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define MX 505
VI r[200005];
int cp[200005];
int n, m;
int x[MX], y[MX];

int d[MX];
int p[MX];

int getRod(int l)
{
	if(cp[l]<r[l].size())
	{
		return r[l][cp[l]++];
	}
	return -1;
}

int go(int c)
{
	int x = getRod(d[c]+(c==n?d[1]:d[c+1]));

	if(x!=-1)
	{
		p[c==n?1:(c+1)] = x;
		if(c>=n-1) return 1;
		return go(c+2);
	}

	x = getRod(d[c]+d[c-1]);
	if(x!=-1)
	{
		p[c] = x;
		if(c==n) return 1;
		return go(c+1);
	}

	return 0;
}

int go2(int c)
{
	int x = getRod(d[c]+d[c+1]);

	if(x!=-1)
	{
		p[c+1] = x;
		if(c>=n-2) return 1;
		return go2(c+2);
	}

	x = getRod(d[c]+d[c-1]);
	if(x!=-1)
	{
		p[c] = x;
		if(c==n-1) return 1;
		return go2(c+1);
	}

	return 0;
}

int main()
{
	int i, j, k;
	n=SI; m=SI;
	for(i=1;i<=n;i++) x[i]=SI, y[i]=SI;
	for(i=1;i<=m;i++) r[SI].PB(i);

	for(i=1;i<n;i++) d[i] = ABS(x[i]-x[i+1]) + ABS(y[i]-y[i+1]);
	d[n] = ABS(x[n]-x[1]) + ABS(y[n]-y[1]);

	int ok = 0;

	SET(cp,0); SET(p,-1);
	p[2] = getRod(d[1]+d[2]);
	if(p[2]!=-1)
	{
		ok = go(3);
		if(ok)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d ",p[i]);
			puts("");
			return 0;
		}
	}
	
	SET(cp,0); SET(p,-1);
	p[1] = getRod(d[1]+d[n]);
	if(p[1]!=-1)
	{
		ok = go2(2);
		if(ok)
		{
			puts("YES");
			for(i=1;i<=n;i++) printf("%d ",p[i]);
			puts("");
			return 0;
		}
	}

	puts("NO");
	
	return 0;
}