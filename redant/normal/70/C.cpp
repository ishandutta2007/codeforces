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

#define MX 100001

int rev(int x)
{
	int rx = 0, y = x;
	while(y){ rx=rx*10+y%10; y/=10; }
	return rx;
}

PI xbrx[MX];
map<PI,VI> M;

int B[MX];

int Q(int x)
{
	int r=0;
	for(;x;x-=x&-x) r+=B[x];
	return r;
}

void U(int x)
{
	for(;x<MX;x+=x&-x) B[x]++;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in1.in","r",stdin);
	#endif
	
	int mx = SI, my = SI, w = SI;
	
	for(int i=1;i<MX;i++)
	{
		int x = i, rx = rev(x), g = __gcd(x,rx);
		x/=g; rx/=g;
		xbrx[i] = MP(x,rx);
	}
	
	for(int i=1;i<=my;i++)
	{
		PI k = MP(xbrx[i].S,xbrx[i].F);
		if(M.count(k)>0) M[k].PB(i);
		else{ M[k]=vector<int>(); M[k].PB(i); }
	}
	
	int rx = -1, ry = -1;
	
	multiset<int> S;
	
	for(int x=1;x<=mx;x++) if(M.count(xbrx[x]))
	{
		VI &v = M[xbrx[x]];
		
		for(vector<int>::iterator it = v.begin();it!=v.end();it++)
			U(*it);
			
		if(Q(my)>=w)
		{
			int lo = 1, hi = my;
			
			if(Q(1)>=w) hi=1;
			else
			{
				while(lo+1<hi)
				{
					int md = (lo+hi)>>1;
					if(Q(md)>=w) hi = md;
					else lo = md;
				}
			}
			
			int y = hi;
			
			if(rx==-1) rx=x,ry=y;
			else if(1ll*x*y < 1ll*rx*ry) rx=x,ry=y;
		}
	}
	
	if(rx==-1) puts("-1");
	else printf("%d %d\n",rx,ry);
	
	return 0;
}