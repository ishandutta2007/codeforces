// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char tbl[5][5];
int main()
{
	scanf("%s %s %s",tbl[0],tbl[1],tbl[2]);
	int i,j,no=0,nx=0,wo=0,wx=0;
	for ( i=0; i<3; i++ )
		for ( j=0; j<3; j++ )
			if ( tbl[i][j]=='0' ) no++;
			else if ( tbl[i][j]=='X' ) nx++;
	for ( i=0; i<3; i++ ) {
		for ( j=0; j<3; j++ )
			if ( tbl[i][j]!=tbl[i][0] ) break;
		if ( j<3 ) continue;
		if ( tbl[i][0]=='0' ) wo=1;
		else if ( tbl[i][0]=='X' ) wx=1;
	}
	for ( i=0; i<3; i++ ) {
		for ( j=0; j<3; j++ )
			if ( tbl[j][i]!=tbl[0][i] ) break;
		if ( j<3 ) continue;
		if ( tbl[0][i]=='0' ) wo=1;
		else if ( tbl[0][i]=='X' ) wx=1;
	}
	for ( i=0; i<3; i++ )
		if ( tbl[i][i]!=tbl[0][0] ) break;
	if ( i==3 ) {
		if ( tbl[0][0]=='0' ) wo=1;
		else if ( tbl[0][0]=='X' ) wx=1;
	}
	for ( i=0; i<3; i++ )
		if ( tbl[i][2-i]!=tbl[0][2] ) break;
	if ( i==3 ) {
		if ( tbl[0][2]=='0' ) wo=1;
		else if ( tbl[0][2]=='X' ) wx=1;
	}
	if ( nx>no+1 || no>nx || (wo&&wx) || (wo&&nx>no) || (wx&&no==nx) ) puts("illegal");
	else if ( wo||wx ) printf("the %s player won\n",no!=nx?"first":"second");
	else if ( no+nx==9 ) puts("draw");
	else if ( no==nx ) puts("first");
	else puts("second");
	return 0;
}