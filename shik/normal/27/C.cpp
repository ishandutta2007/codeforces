// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[100010];
int go( int p ) {
	int v=a[p];
	while ( p<=n && a[p]==v ) p++;
	return p;
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1,j=go(i),k=go(j); k<=n; i=j,j=k,k=go(k) )
		if ( a[i]>a[j]&&a[j]<a[k] || a[i]<a[j]&&a[j]>a[k] ) return printf("3\n%d %d %d\n",i,j,k),0;
	puts("0");
	return 0;
}