// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
	char s[1000],c='a';
	int i;
	gets(s);
	for ( i=0; s[i]; i++ )
		if ( isalpha(s[i]) ) c=tolower(s[i]);
	puts(strchr("aeiouy",c)?"YES":"NO");
	return 0;
}