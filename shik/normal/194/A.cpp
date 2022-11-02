// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for ( int i=0; i<=n; i++ ) {
		int j=n-i;
		if ( 2*i+3*j<=k && k<=2*i+5*j ) return printf("%d\n",i),0;
	}
	return 0;
}