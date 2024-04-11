// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[N][N],r[N],c[N];
int main()
{
	char op;
	int n,m,q,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for ( int i=1; i<=n; i++ ) for ( int j=1; j<=m; j++ ) scanf("%d",a[i]+j);
	for ( int i=1; i<=n; i++ ) r[i]=i;
	for ( int i=1; i<=m; i++ ) c[i]=i;
	while ( q-- ) {
		scanf(" %c%d%d",&op,&x,&y);
		if ( op=='c' ) swap(c[x],c[y]);
		else if ( op=='r' ) swap(r[x],r[y]);
		else printf("%d\n",a[r[x]][c[y]]);
	}
	return 0;
}