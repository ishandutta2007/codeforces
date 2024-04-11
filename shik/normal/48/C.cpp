// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,d;
	double sml=10,big=1e10;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&d);
		sml=max(sml,10.0*d/i);
		big=min(big,10.0*(d+1)/i);
	}
	int lb=(int)((n+1)*sml/10+1e-9);
	int ub=(int)((n+1)*big/10-1e-9);
	if ( lb==ub ) printf("unique\n%d\n",lb);
	else puts("not unique");
	return 0;
}