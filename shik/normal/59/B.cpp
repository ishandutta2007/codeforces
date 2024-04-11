// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int main()
{
	int n,a[N],i,s=0,sml=514;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%d",a+i);
	for ( i=0; i<n; i++ ) s+=a[i];
	if ( s%2==1 ) {
		printf("%d\n",s);
		return 0;
	}
	for ( i=0; i<n; i++ )
		if ( a[i]%2==1 ) sml=min(sml,a[i]);
	if ( sml==514 ) puts("0");
	else printf("%d\n",s-sml);
	return 0;
}