// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[100],t[100];
	scanf("%s %s",s,t);
	sort(s,s+strlen(s));
	if ( s[0]=='0' ) {
		for ( int i=0; s[i]; i++ )
			if ( s[i]!='0' ) {
				swap(s[0],s[i]);
				break;
			}
	}
	puts(strcmp(s,t)==0?"OK":"WRONG_ANSWER");
	return 0;
}