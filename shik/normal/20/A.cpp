// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	char s[200];
	gets(s);
	for ( char *p=strtok(s,"/"); p; p=strtok(0,"/") ) printf("/%s",p);
	if ( strlen(s)==count(s,s+strlen(s),'/') ) putchar('/');
	puts("");
	return 0;
}