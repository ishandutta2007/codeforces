// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
char tbl[N][N];
int cx[N][130],cy[N][130];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for ( i=0; i<n; i++ ) scanf("%s",tbl[i]);
	for ( i=0; i<n; i++ )
		for ( j=0; j<m; j++ ) {
			cx[i][(int)tbl[i][j]]++;
			cy[j][(int)tbl[i][j]]++;
		}
	for ( i=0; i<n; i++ )
		for ( j=0; j<m; j++ )
			if ( cx[i][(int)tbl[i][j]]==1 && cy[j][(int)tbl[i][j]]==1 ) putchar(tbl[i][j]);
	puts("");
	return 0;
}