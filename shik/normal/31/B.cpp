// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[514];
	gets(s);
	int i,j,n=strlen(s);;
	for ( i=0; i<n&&s[i]!='@'; i++ );
	if ( i==0 || i==n ) { puts("No solution"); return 0; }
	j=i;
	for ( i=j+1; i<n; i++ ) if ( s[i]=='@' ) {
		if ( i-j<=2 ) { puts("No solution"); return 0; }
		j=i;
	}
	if ( j==n-1 ) { puts("No solution"); return 0; }
	for ( i=0,j=0; i<n; i++ ) {
		if ( s[i+1]=='@' ) {
			if ( j==0 ) j=1;
			else putchar(',');
		}
		putchar(s[i]);
	}
	puts("");
	return 0;
}