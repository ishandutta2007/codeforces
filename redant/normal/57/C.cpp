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

#define MX 100003

LL mpow(LL a, int n, LL m)
{
	if(n==0) return 1;
	if(n==1) return a%m;
	LL b = mpow(a,n/2,m);
	b=(b*b)%m;
	if(n&1) b=(b*a)%m;
	return b;
}

LL f[2*MX];
LL invf[MX];

int main()
{
	f[0]=invf[0]=1;
	int n=SI, m = 1000000007;

	for(int i=1;i<=2*n;i++) f[i] = (f[i-1]*i)%m;
	for(int i=1;i<=n;i++) invf[i] = (invf[i-1]*mpow(i,m-2,m))%m;

	LL r = ( ( (f[2*n]*invf[n])%m ) * invf[n] ) %m;
	r = (r+m-n)%m;

	cout<<r<<endl;

	return 0;
}