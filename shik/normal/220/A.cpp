// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[100010],b[100010];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) b[i]=a[i];
	sort(b,b+n);
	int c=0,w[3];
	for ( int i=0; i<n&&c<=2; i++ ) if ( a[i]!=b[i] ) w[c++]=i;
	if ( c>2 ) return puts("NO"),0;
	if ( c<2 ) return puts("YES"),0;
	swap(a[w[0]],a[w[1]]);
	for ( int i=0; i<n; i++ ) if ( a[i]!=b[i] ) return puts("NO"),0;
	puts("YES");
	return 0;
}