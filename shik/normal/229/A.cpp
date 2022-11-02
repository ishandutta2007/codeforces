// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define M 10010
#define INF 5000000
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N][M];
int a[N][3*M],d[N][3*M];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%s",s[i]);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<3*m; j++ ) a[i][j]=(s[i][j%m]=='1');
	for ( int i=0; i<n; i++ ) for ( int j=0; j<3*m; j++ ) d[i][j]=INF;
	for ( int i=0; i<n; i++ ) for ( int j=1; j<3*m; j++ ) d[i][j]=min(d[i][j],a[i][j]?0:d[i][j-1]+1);
	for ( int i=0; i<n; i++ ) for ( int j=3*m-2; j>=0; j-- ) d[i][j]=min(d[i][j],a[i][j]?0:d[i][j+1]+1);
	int ans=INF,now;
	for ( int j=0; j<3*m; j++ ) {
		for ( int i=now=0; i<n; i++ ) now+=d[i][j];
		ans=min(ans,now);
	}
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}