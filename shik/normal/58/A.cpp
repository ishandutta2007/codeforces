// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[110],t[6]="hello",*p=s;
	gets(s);
	for ( int i=0; i<5; i++ ) {
		p=strchr(p,t[i]);
		if ( !p ) break;
		else p++;
	}
	puts(p?"YES":"NO");
	return 0;
}