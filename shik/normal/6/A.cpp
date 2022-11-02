// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a[4],i,flg=0;
	for ( i=0; i<4; i++ ) scanf("%d",a+i);
	sort(a,a+4);
	for ( i=0; i<2; i++ )
		if ( a[i]+a[i+1]>a[i+2] ) flg|=2;
		else if ( a[i]+a[i+1]==a[i+2] ) flg|=1;
	if ( flg>=2 ) puts("TRIANGLE");
	else if ( flg>=1 ) puts("SEGMENT");
	else puts("IMPOSSIBLE");
	return 0;
}