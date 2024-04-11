// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	while ( n>1 ) {
		printf("%d ",n);
		for ( i=2; i<=n; i++ )
			if ( n%i==0 ) {
				n/=i;
				break;
			}
	}
	puts("1");
	return 0;
}