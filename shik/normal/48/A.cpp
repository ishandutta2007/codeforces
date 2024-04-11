// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool win( char *a, char *b ) {
	if ( a[0]=='s' && b[0]=='p' ) return 1;
	if ( a[0]=='p' && b[0]=='r' ) return 1;
	if ( a[0]=='r' && b[0]=='s' ) return 1;
	return 0;
}
int main()
{
	char a[10],b[10],c[10];
	scanf("%s %s %s",a,b,c);
	if ( win(a,b) && win(a,c) ) puts("F");
	else if ( win(b,a) && win(b,c) ) puts("M");
	else if ( win(c,a) && win(c,b) ) puts("S");
	else puts("?");
	return 0;
}