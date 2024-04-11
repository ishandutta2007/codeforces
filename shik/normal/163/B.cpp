// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P { int id,w,v; } p[N];
inline bool operator <( const P &a, const P &b ) { return a.w!=b.w?a.w<b.w:a.v<b.v; }
int n,k,h;
int sol[N],ans[N];
bool chk( long double t ) {
	for ( int i=1,j=0; i<=k; i++ ) {
		while ( j<n && p[j].v*t<i*h ) j++;
		if ( j==n ) return 0;
		sol[i]=p[j].id;
		j++;
	}
	memcpy(ans+1,sol+1,k*sizeof(int));
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&k,&h);
	for ( int i=0; i<n; i++ ) p[i].id=i+1;
	for ( int i=0; i<n; i++ ) scanf("%d",&p[i].w);
	for ( int i=0; i<n; i++ ) scanf("%d",&p[i].v);
	sort(p,p+n);
	long double L=0,R=1e10;
	for ( int i=0; i<100; i++ ) {
		long double M=(L+R)/2;
		if ( chk(M) ) R=M;
		else L=M;
	}
	for ( int i=1; i<=k; i++ ) printf("%d%c",ans[i],i==k?'\n':' ');
	return 0;
}