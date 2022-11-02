// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char tbl[10][10];
	int ans=0,cx[10]={},cy[10]={};
	for ( int i=0; i<8; i++ ) scanf("%s",tbl[i]);
	for ( int i=0; i<8; i++ )
		for ( int j=0; j<8; j++ )
			if ( tbl[i][j]=='B' ) cx[i]++,cy[j]++;
	for ( int i=0; i<8; i++ ) {
		if ( cx[i]==8 ) ans++;
		if ( cy[i]==8 ) ans++;
	}
	if ( ans==16 ) ans=8;
	printf("%d\n",ans);
	return 0;
}