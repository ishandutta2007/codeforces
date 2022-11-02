// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int a,b,n,flg=0;
	scanf("%d%d%d",&a,&b,&n);
	while ( n ) {
		if ( flg==0 ) n-=__gcd(a,n);
		else n-=__gcd(b,n);
		flg^=1;
	}
	printf("%d\n",flg^1);
	return 0;
}