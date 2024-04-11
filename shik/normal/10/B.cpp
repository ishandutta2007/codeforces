// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define INF 514514514
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,c,tbl[N][N];
int eval( int x, int y1, int y2 ) {
	int r=0;
	r+=(y2-y1+1)*abs(x-c);
	if ( c>y2 ) r+=(y2-y1)*(y2-y1-1)/2 + (y2-y1+1)*(c-y2);
	else if ( c<y1 ) r+=(y2-y1)*(y2-y1-1)/2 + (y2-y1+1)*(y1-c);
	else r+=(c-y1)*(c-y1-1)/2 + (y2-c)*(y2-c-1)/2;
	return r;
}
void solve( int q ) {
	int sml=INF,wx=0,wy1=0,wy2=0;
	for ( int i=1; i<=n; i++ ) {
		int cnt=0;
		for ( int j=1; j<=n; j++ ) {
			if ( tbl[i][j] ) cnt=0;
			else if ( ++cnt>=q ) {
				int val=eval(i,j-q+1,j);
				if ( val<sml ) {
					sml=val;
					wx=i; wy1=j-q+1; wy2=j;
				}
			}
		}
	}
	if ( sml==INF ) puts("-1");
	else {
		for ( int i=wy1; i<=wy2; i++ ) tbl[wx][i]=1;
		printf("%d %d %d\n",wx,wy1,wy2);
	}
}
int main()
{
	int m,q;
	scanf("%d%d",&m,&n); c=(n+1)/2;
	while ( m-- ) {
		scanf("%d",&q);
		solve(q);
	}
	return 0;
}