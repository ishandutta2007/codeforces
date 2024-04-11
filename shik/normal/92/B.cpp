// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define L 1000010
using namespace std;
char s[L];
int main()
{
	int n=strlen(gets(s)),ans=0;
	while ( s[n-1]=='0' ) {
		ans++;
		n--;
	}
	if ( n==1 ) {
		printf("%d\n",ans);
		return 0;
	}
	for ( int i=0; i<n; i++ )
		if ( s[i]=='0' ) ans++;
	printf("%d\n",ans+n+1);
	return 0;
}