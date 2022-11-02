// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,l[100010],r[100010];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",l+i,r+i);
	int lb=*min_element(l,l+n);
	int rb=*max_element(r,r+n);
	for ( int i=0; i<n; i++ ) if ( l[i]<=lb && rb<=r[i] ) return printf("%d\n",i+1),0;
	puts("-1");
	return 0;
}