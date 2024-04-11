// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 333
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
int d[N][N];
int main()
{
	int n,m,a,b,c;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) scanf("%d",d[i]+j);
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		long long ans=0;
		for ( int i=1; i<=n; i++ ) for ( int j=1; j<=n; j++ ) {
			chkmin(d[i][j],d[i][a]+c+d[b][j]);
			chkmin(d[i][j],d[i][b]+c+d[a][j]);
			ans+=d[i][j];
		}
		printf("%I64d%c",ans/2,m==0?'\n':' ');
	}
	return 0;
}