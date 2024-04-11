// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a[210];
	scanf("%d",&n);
	for ( int i=0; i<2*n; i++ ) scanf("%1d",a+i);
	sort(a,a+n);
	sort(a+n,a+n+n);
	for ( int i=0; i<n; i++ ) if ( a[i]==a[i+n] ) { puts("NO"); return 0; }
	for ( int i=0; i<n; i++ ) if ( (a[i]<a[i+n])^(a[0]<a[n]) ) { puts("NO"); return 0; }
	puts("YES");
	return 0;
}