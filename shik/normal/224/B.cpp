// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int v[N],a[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) {
		if ( v[a[i]]++==0 ) k--;
		if ( k==0 ) {
			int r=i,l=1;
			while ( v[a[l]]>1 ) v[a[l++]]--;
			return printf("%d %d\n",l,r),0;
		}
	}
	puts("-1 -1");
	return 0;
}