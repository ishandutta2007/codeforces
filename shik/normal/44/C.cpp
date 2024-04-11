// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,cnt[110]={},a,b;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		for ( int i=a; i<=b; i++ ) cnt[i]++;
	}
	for ( int i=1; i<=n; i++ ) if ( cnt[i]!=1 ) {
		printf("%d %d\n",i,cnt[i]);
		return 0;
	}
	puts("OK");
	return 0;
}