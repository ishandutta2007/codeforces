// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int lst[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<14; i++ )
		if ( n%lst[i]==0 ) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}