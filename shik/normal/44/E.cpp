// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a,b,l,p=0;
	char s[210];
	scanf("%d%d%d %s",&n,&a,&b,s);
	l=strlen(s);
	if ( l<n*a || l>n*b ) { puts("No solution"); return 0; }
	while ( n-- ) {
		for ( int i=0; i<a; i++ ) putchar(s[p++]);
		while ( l-p>n*b ) putchar(s[p++]);
		puts("");
	}
	return 0;
}