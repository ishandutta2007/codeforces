// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,a[55],b[55],ans=0,big=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	scanf("%d",&m);
	for ( int i=0; i<m; i++ ) scanf("%d",b+i);
	for ( int i=0; i<n; i++ ) for ( int j=0; j<m; j++ ) if ( b[j]%a[i]==0 ) {
		int v=b[j]/a[i];
		if ( v>big ) {
			big=v;
			ans=1;
		} else if ( v==big ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}