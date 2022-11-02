// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[1000];
	gets(s);
	for ( int i=0; s[i]; i++ )
		if ( s[i]=='.' ) putchar('0');
		else if ( s[++i]=='.' ) putchar('1');
		else putchar('2');
	puts("");
	return 0;
}