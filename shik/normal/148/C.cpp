// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if ( a>0 && b==0 ) {
		if ( n==a+b+1 ) return puts("-1"),0;
		else {
			printf("1 ");
			n--;
		}
	}
	putchar('1');
	for ( int i=1; i<=b; i++ ) printf(" %d",1<<i);
	for ( int i=1; i<=a; i++ ) printf(" %d",(1<<b)+i);
	for ( int i=0; i<n-a-b-1; i++ ) printf(" 1");
	puts("");
	return 0;
}