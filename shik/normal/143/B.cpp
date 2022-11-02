// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[1000];
	gets(s);
	if ( s[0]=='-' ) putchar('(');
	putchar('$');
	int p=strchr(s,'.')?strchr(s,'.')-s:strlen(s);
	for ( int i=(s[0]=='-'); i<p; i++ ) {
		if ( i>(s[0]=='-') && (p-i)%3==0 ) putchar(',');
		putchar(s[i]);
	}
	putchar('.');
	for ( int i=1; i<=2; i++ ) putchar(i+p>=(int)strlen(s)?'0':s[i+p]);
	if ( s[0]=='-' ) putchar(')');
	puts("");
	return 0;
}