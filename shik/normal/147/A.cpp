// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[10010],t[10010];
int main()
{
	gets(s);
	int first=1;
	for ( int i=0,j; s[i]; i=j ) {
		if ( s[i]==' ' ) { j=i+1; continue; }
		if ( !isalpha(s[i]) ) {
			putchar(s[i]);
			j=i+1;
			continue;
		}
		if ( !first ) putchar(' ');
		for ( j=i; isalpha(s[j]); j++ ) putchar(s[j]);
		first=0;
	}
	puts("");
	return 0;
}