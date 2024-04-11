// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,a[100010];
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	int *sml=min_element(a,a+n);
	if ( count(a,a+n,*sml)>1 ) puts("Still Rozdil");
	else printf("%ld\n",sml-a+1);
	return 0;
}