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
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1,j=n; i<=j; i++,j-- ) {
		if ( a[i]-i>=0 ) c[a[i]-i]++;
		if ( j>i && a[j]-i>=0 ) c[a[j]-i]++;
	}
	printf("%d\n",n-*max_element(c,c+N));
	return 0;
}