// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <functional>
#define N 514
#define M 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,a[N];
LL p[N];
pair<LL,int> inp[N];
void input() {
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%I64d%d",&inp[i].first,&inp[i].second);
	sort(inp,inp+n);
	for ( int i=0; i<n; i++ ) {
		p[i]=inp[i].first;
		a[i]=inp[i].second;
	}
}
long long v;
int gap,top[N],fac[M],fn;
void gen( int x, int s ) {
	if ( x==n || s>top[x] ) {
		fac[fn++]=s;
		return;
	}
	for ( int i=0; i<=a[x]; i++ ) {
		gen(x+1,s);
		if ( s<=top[x] ) s*=p[x];
		else break;
	}
}
void build() {
	v=1;
	for ( int i=0; i<n; i++ ) for ( int j=0; j<a[i]; j++ ) v*=p[i];
	gap=(int)(sqrt((long double)v)+1e-9);
	for ( int i=0; i<n; i++ ) top[i]=gap/p[i];
	fn=0; gen(0,1);
	sort(fac,fac+fn);
}
void solve() {
	LL ans=2*(1+v+v),xx=1,yy=1,zz=v;
	int tmt=(int)(cbrt((long double)v)+1e-9);
	for ( int i=0; i<fn&&fac[i]<=tmt; i++ ) {
		LL x=fac[i];
		LL yz=v/x;
		LL upy=(LL)(sqrt((long double)yz)+1e-9);
		int j=upper_bound(fac,fac+fn,upy)-fac-1;
		while ( yz%fac[j]!=0 ) j--;
		LL y=fac[j];
		LL z=yz/y;
		LL tmp=2*(x*y+y*z+z*x);
		if ( tmp<ans ) {
			ans=tmp;
			xx=x; yy=y; zz=z;
		}
	}
	printf("%I64d %I64d %I64d %I64d\n",ans,xx,yy,zz);
}
int main()
{
	int t;
	scanf("%d",&t);
	while ( t-- ) {
		input();
		build();
		solve();
	}
	return 0;
}