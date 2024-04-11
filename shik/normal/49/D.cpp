// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,c=0,x;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%1d",&x);
		if ( x==i%2 ) c++;
	}
	printf("%d\n",min(c,n-c));
	return 0;
}