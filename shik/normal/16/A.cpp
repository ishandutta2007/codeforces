// by shik
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,tbl[110][110],i,j;
	scanf("%d%d",&n,&m);
	for ( i=0; i<n; i++ )
		for ( j=0; j<m; j++ )
			scanf("%1d",&tbl[i][j]);
	for ( i=0; i<n; i++ ) {
		for ( j=1; j<m; j++ )
			if ( tbl[i][j]!=tbl[i][j-1] ) break;
		if ( j!=m ) { puts("NO"); return 0; }	
	}
	for ( i=1; i<n; i++ )
		if ( tbl[i][0]==tbl[i-1][0] ) break;
	if ( i==n ) puts("YES");
	else puts("NO");
	return 0;
}