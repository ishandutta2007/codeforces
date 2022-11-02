// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a=0,b=0;
	char s[66];
	scanf("%d %s",&n,s);
	for ( int i=0; i<n; i++ ) if ( s[i]!='4' && s[i]!='7' ) { puts("NO"); return 0; }
	a=accumulate(s,s+n/2,0);
	b=accumulate(s+n/2,s+n,0);
	puts(a==b?"YES":"NO");
	return 0;
}