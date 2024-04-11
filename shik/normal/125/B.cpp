// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[100];
	int lv=0;
	while ( scanf("<%[^>]>",s)==1 ) {
		if ( s[0]=='/' ) lv--;
		for ( int i=0; i<lv; i++ ) printf("  ");
		printf("<%s>\n",s);
		if ( s[0]!='/' ) lv++;
	}
	return 0;
}