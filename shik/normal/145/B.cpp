// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int c4,c7,c47,c74;
	scanf("%d%d%d%d",&c4,&c7,&c47,&c74);
	if ( abs(c47-c74)>1 ) return puts("-1"),0;
	if ( c47>min(c4,c7) || c74>min(c4,c7) ) return puts("-1"),0;
	if ( c4==c7 && c4==c47 && c4==c74 ) return puts("-1"),0;
	if ( c47>c74 ) {
		for ( int i=0; i<c4-c47; i++ ) putchar('4');
		for ( int i=0; i<c47; i++ ) printf("47");
		for ( int i=0; i<c7-c47; i++ ) putchar('7');
	} else if ( c47<c74 ) {
		if ( c7==c74 ) {
			putchar('7');
			for ( int i=0; i<=c4-c74; i++ ) printf("4");
			for ( int i=0; i<c74-1; i++ ) printf("74");
		} else if ( c74==1 ) {
			for ( int i=0; i<c7; i++ ) putchar('7');
			for ( int i=0; i<c4; i++ ) putchar('4');
		} else {
			putchar('7');
			for ( int i=0; i<=c4-c74; i++ ) printf("4");
			for ( int i=0; i<c74-2; i++ ) printf("74");
			for ( int i=0; i<=c7-c74; i++ ) putchar('7');
			putchar('4');
		}
	} else {
		if ( c4>c47 ) {
			for ( int i=0; i<c4-c47-1; i++ ) putchar('4');
			for ( int i=0; i<c47; i++ ) printf("47");
			for ( int i=0; i<c7-c47; i++ ) putchar('7');
			putchar('4');
		} else {
			putchar('7');
			for ( int i=0; i<=c4-c74; i++ ) putchar('4');
			for ( int i=0; i<c74-1; i++ ) printf("74");
			for ( int i=0; i<c7-c74; i++ ) putchar('7');
		}
	}
	puts("");
	return 0;
}