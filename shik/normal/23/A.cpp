// by shik
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[200];
int n;
bool ok( int st, int len ) {
	int r=0,i;
	for ( i=0; i<n&&r<2; i++ )
		if ( strncmp(s+i,s+st,len)==0 ) r++;
	return r>=2;
}
int main()
{
	int L,i; 
	n=strlen(gets(s));
	for ( L=n; L>0; L-- )
		for ( i=0; i+L<=n; i++ )
			if ( ok(i,L) ) {
				printf("%d\n",L);
				return 0;	
			}
	puts("0");
	return 0;
}