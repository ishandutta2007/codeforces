// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a,b,ans=0;
	scanf("%d%d%d",&n,&a,&b);
	for ( int i=1; i<=n; i++ )
		if ( i-1>=a && n-i<=b ) ans++;
	printf("%d\n",ans);
	return 0;
}