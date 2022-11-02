// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
int main()
{
	char s[200];
	int c1=0,c2=0,i;
	scanf("%s",s);
	for ( i=0; s[i]; i++ )
		if ( isupper(s[i]) ) c1++;
		else if ( islower(s[i]) ) c2++;
	if ( c1>c2 )
		for ( i=0; s[i]; i++ ) s[i]=toupper(s[i]);
	else
		for ( i=0; s[i]; i++ ) s[i]=tolower(s[i]);
	puts(s);
	return 0;
}