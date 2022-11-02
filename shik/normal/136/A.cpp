// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,ans[110];
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&x);
		ans[x]=i;
	}
	for ( int i=1; i<=n; i++ ) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}