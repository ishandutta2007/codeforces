// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char s[200];
	int n=strlen(gets(s));
	for ( int i=1; i<n; i++ )
		if ( s[i]=='a' && s[i+1]=='t' ) {
			s[i]='@';
			for ( int j=i+1; j<n; j++ ) s[j]=s[j+1];
			n--;
			break;
		}
	for ( int i=0; i<n; i++ ) {
		if ( i==0 || i==n-3 ) putchar(s[i]);
		else if ( strncmp(s+i,"dot",3)==0 ) {
			putchar('.');
			i+=2;
		} else putchar(s[i]);
	}
	puts("");
	return 0;
}