// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char tbl[5][5];
int main()
{
	scanf("%s%s%s",tbl[0],tbl[1],tbl[2]);
	int f=1;
	for ( int i=0; i<3; i++ )
		for ( int j=0; j<3; j++ )
			if ( tbl[i][j]!=tbl[2-i][2-j] ) f=0;
	puts(f?"YES":"NO");
	return 0;
}