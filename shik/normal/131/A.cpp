// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[210];
	gets(s);
	for ( int i=1; s[i]; i++ ) if ( islower(s[i]) ) return puts(s),0;
	for ( int i=0; s[i]; i++ ) s[i]^=32;
	puts(s);
	return 0;
}