// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[100010];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	if ( a[n-1]==1 ) a[n-1]=2;
	else a[n-1]=1;
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) printf("%d%c",a[i],i==n-1?'\n':' ');
	return 0;
}