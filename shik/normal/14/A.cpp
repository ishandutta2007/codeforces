// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,flg;
	char tbl[100][100];
	scanf("%d%d",&n,&m);
	int L=0,R=m-1,U=0,D=n-1;
	for ( int i=0; i<n; i++ ) scanf("%s",tbl[i]);
	do {
		flg=1;
		for ( int i=0; i<m; i++ )
			if ( tbl[U][i]=='*' ) flg=0;
		if ( flg ) U++;
	} while ( flg );
	do {
		flg=1;
		for ( int i=0; i<m; i++ )
			if ( tbl[D][i]=='*' ) flg=0;
		if ( flg ) D--;
	} while ( flg );
	do {
		flg=1;
		for ( int i=0; i<n; i++ )
			if ( tbl[i][L]=='*' ) flg=0;
		if ( flg ) L++;
	} while ( flg );
	do {
		flg=1;
		for ( int i=0; i<n; i++ )
			if ( tbl[i][R]=='*' ) flg=0;
		if ( flg ) R--;
	} while ( flg );
	for ( int i=U; i<=D; i++ ) {
		for ( int j=L; j<=R; j++ ) putchar(tbl[i][j]);
		puts("");
	}
	return 0;
}