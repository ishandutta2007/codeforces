// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,k,a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=n; i>k; i-- ) if ( a[i]!=a[k] ) return puts("-1"),0;
	int ans=k;
	while ( ans>0 && a[ans]==a[k] ) ans--;
	printf("%d\n",ans);
	return 0;
}