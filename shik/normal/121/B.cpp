// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int s[100010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%1d",s+i);
	for ( int i=1; i<=n&&m>0; i++ )
		if ( s[i]==4 && s[i+1]==7 ) {
			if ( s[i-1]==4 && i%2==0 ) {
				if ( m%2 ) s[i]=7;
				break;
			} else if ( s[i+2]==7 && i%2==1 ) {
				if ( m%2 ) s[i+1]=4;
				break;
			} else {
				m--;
				if ( i&1 ) s[i+1]=4;
				else s[i]=7;
			}
		}
	for ( int i=1; i<=n; i++ ) printf("%d",s[i]); puts("");
	return 0;
}