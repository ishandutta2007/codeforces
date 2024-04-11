// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int x[6];
	for ( int i=0; i<6; i++ ) scanf("%d",x+i);
	for ( int i=0; i<3; i++ )
		if ( x[i]==x[i+3] ) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}