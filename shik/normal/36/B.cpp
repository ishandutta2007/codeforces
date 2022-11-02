// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
char ptn[5][5],tbl[300][300];
int n;
void draw( int x, int y, int L ) {
	for ( int i=x; i<x+L; i++ )
		for ( int j=y; j<y+L; j++ )
			tbl[i][j]='*';
}
void go( int x, int y, int L ) {
	if ( L==1 ) return;
	int g=L/n,i,j,p,q;
	for ( i=x,p=0; i<x+L; i+=g,p++ )
		for ( j=y,q=0; j<y+L; j+=g,q++ )
			if ( ptn[p][q]=='*' ) draw(i,j,g);
			else go(i,j,g);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k,i,j,L;
	scanf("%d%d ",&n,&k);
	for ( i=0; i<n; i++ ) gets(ptn[i]);
	L=1;
	while ( k-- ) L*=n;
	for ( i=0; i<L; i++ )
		for ( j=0; j<L; j++ )
			tbl[i][j]='.';
	go(0,0,L);
	for ( i=0; i<L; i++ ) puts(tbl[i]);
	return 0;
}