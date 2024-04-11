// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200
using namespace std;
int sz[N],a,b,c,d;
char tbl[N][N];
void go( int &x, int &y, int &dir ) {
	if ( dir==1 ) {
		if ( y>0 && tbl[x][y-1]!='.' ) y--;
		else {
			x++;
			dir=2;
		}
	} else {
		if ( y<a+c-1 && tbl[x][y+1]!='.' ) y++;
		else {
			x++;
			dir=1;
		}
	}
}
int main()
{
	int n,i,j,x=0,y,dir;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	for ( i=0; i<n; i++ ) scanf("%d",sz+i);
	if ( b>d )
		for ( i=d; i<b; i++ )
			for ( j=a; j<a+c; j++ )
				tbl[i][j]='.';
	else
		for ( i=b; i<d; i++ )
			for ( j=0; j<a; j++ )
				tbl[i][j]='.';
	if ( (b>d&&d%2==1) || (b<d&&b%2==0) ) y=a+c-1,dir=1;
	else y=0,dir=2;
	for ( i=0; i<n; i++ ) {
		for ( j=0; j<sz[i]; j++ ) {
			tbl[x][y]='a'+i;
			go(x,y,dir);
		}
	}
	puts("YES");
	for ( i=0; i<max(b,d); i++ ) puts(tbl[i]);
	return 0;
}