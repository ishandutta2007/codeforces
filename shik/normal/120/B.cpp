// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,a[1010];
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	while ( a[m]==0 ) {
		m++;
		if ( m>n ) m=1;
	}
	printf("%d\n",m);
	return 0;
}