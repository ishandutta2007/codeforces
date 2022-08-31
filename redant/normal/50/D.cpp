#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

#define eps 1e-8
#define inf int(2e9)
#define MXN 105

int x, y, xc, yc;
int n, k, e;
int d2[MXN];
double P[MXN];

bool ok(double m)
{
	double r2 = m*m;

	REP(i,k) P[i] = 0.0;
	P[0] = 1.0;
	
	for(int i=0;i<n;i++)
	{
		double p = (d2[i]<r2+eps) ? 1.0 : exp(1.0-(d2[i]/r2));
		for(int j=k-1;j>=0;j--)
		{
			P[j] = (P[j]*(1-p));
			if(j>0) P[j] += (P[j-1]*p);
		}
	}

	double lose = 0.0;
	for(int j=0;j<k;j++) lose += P[j];

	return lose*1000 < e-eps;
}

int main()
{
	n=SI; 
	k=SI; e=SI;
	xc=SI; yc=SI;
	REP(i,n)
	{ 
		x=SI; y=SI;
		d2[i] = (x-xc)*(x-xc) + (y-yc)*(y-yc);
	}


	double lo = 0.0, hi = 10010;
	
	REP(t,200)
	{
		double m = (lo+hi)/2.0;
		if(ok(m)) hi=m; else lo=m;
	}

	printf("%.10lf\n",(lo+hi)/2.0);

	return 0;
}