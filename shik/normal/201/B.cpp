// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) (int)((x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,m,a[N][N];
LL sqr( int x ) { return x*x; }
LL get( int x, int y ) {
	x*=2; y*=2;
	LL r=0;
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) r+=a[i][j]*(sqr(2*i-1-x)+sqr(2*j-1-y));
	return r;
}
int main()
{
	LL sx=0,sy=0,s=0;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) {
		scanf("%d",a[i]+j);
		sx+=1LL*i*a[i][j];
		sy+=1LL*j*a[i][j];
		s+=a[i][j];
	}
	if ( s ) { sx/=s; sy/=s; }
	LL ans=(1LL<<60);
	int ax=-1,ay=-1;
	for ( int i=-1; i<=1; i++ ) for ( int j=-1; j<=1; j++ ) {
		int x=sx+i,y=sy+j;
		if ( x>=0 && x<=n && y>=0 && y<=m ) {
			LL now=get(x,y);
			if ( now<ans ) {
				ans=now;
				ax=x; ay=y;
			}
		}
	}
	printf("%I64d\n%d %d\n",4*ans,ax,ay);
	return 0;
}