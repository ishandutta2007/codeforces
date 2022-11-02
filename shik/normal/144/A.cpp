// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,a[110],sml,big,ps,pb;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sml=*min_element(a,a+n);
	big=*max_element(a,a+n);
	for ( ps=n-1; a[ps]!=sml; ps-- );
	for ( pb=0; a[pb]!=big; pb++ );
	printf("%d\n",pb+n-1-ps-(ps<pb));
	return 0;
}