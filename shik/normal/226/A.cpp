// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a=1,p=3;
	while ( n ) {
		if ( n&1 ) a=1LL*p*a%m;
		n>>=1;
		p=1LL*p*p%m;
	}
	a=(a+m-1)%m;
	printf("%d\n",a);
	return 0;
}