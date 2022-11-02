// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[N],c[N];
int main()
{
	scanf("%d",&n);
	if ( n%2 ) return puts("NO"),0;
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	if ( a[n-1]-a[0]>=n || a[0]==a[n-1] ) return puts("NO"),0;
	for ( int i=n-1; i>=0; i-- ) a[i]-=a[0];
	for ( int i=0; i<n; i++ ) c[a[i]]++;
	int m=a[n-1];
	c[0]--; c[m]--;
	for ( int i=1; i<m; i++ ) if ( c[i]<2 ) return puts("NO"),0;
	for ( int i=1; i<m; i++ ) c[i]-=2;
	for ( int i=0; i<=m; i++ ) while ( c[i]>0 ) {
		if ( c[i+1]==0 ) return puts("NO"),0;
		c[i]--; c[i+1]--;
	}
	puts("YES");
	return 0;
}