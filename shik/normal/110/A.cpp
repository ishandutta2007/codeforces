// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[200];
	scanf("%s",s);
	int c=0;
	for ( int i=0; s[i]; i++ )
		if ( s[i]=='4' || s[i]=='7' ) c++;
	if ( c==4 || c==7 ) puts("YES");
	else puts("NO");
	return 0;
}