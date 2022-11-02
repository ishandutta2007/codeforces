// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,a[N][N],x[N],y[N],ax[N],ay[N];
inline void fx( int i ) {
	ax[i]^=1;
	for ( int j=1; j<=m; j++ ) {
		a[i][j]*=-1;
		x[i]+=2*a[i][j];
		y[j]+=2*a[i][j];
	}
}
inline void fy( int j ) {
	ay[j]^=1;
	for ( int i=1; i<=n; i++ ) {
		a[i][j]*=-1;
		x[i]+=2*a[i][j];
		y[j]+=2*a[i][j];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",a[i]+j);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) x[i]+=a[i][j],y[j]+=a[i][j];
	while ( 1 ) {
		int stop=1;
		for ( int i=1; i<=n; i++ ) if ( x[i]<0 ) fx(i),stop=0;
		for ( int i=1; i<=m; i++ ) if ( y[i]<0 ) fy(i),stop=0;
		if ( stop ) break;
	}
	int nx=count(ax+1,ax+n+1,1),ny=count(ay+1,ay+m+1,1);
	printf("%d",nx);
	for ( int i=1; i<=n; i++ ) if ( ax[i] ) printf(" %d",i); puts("");
	printf("%d",ny);
	for ( int i=1; i<=m; i++ ) if ( ay[i] ) printf(" %d",i); puts("");
	return 0;
}