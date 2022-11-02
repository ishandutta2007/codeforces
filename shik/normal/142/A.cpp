// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n;
	long long sml=1LL<<60,big=0;
	scanf("%d",&n);
	for ( int i=1; i*i*i<=n; i++ ) if ( n%i==0 )
		for ( int j=i; i*j*j<=n; j++ ) if ( n/i%j==0 ) {
			int k=n/i/j;
			big=max(big,1LL*(i+1)*(j+2)*(k+2));
			big=max(big,1LL*(i+2)*(j+1)*(k+2));
			big=max(big,1LL*(i+2)*(j+2)*(k+1));
			sml=min(sml,1LL*(i+1)*(j+2)*(k+2));
			sml=min(sml,1LL*(i+2)*(j+1)*(k+2));
			sml=min(sml,1LL*(i+2)*(j+2)*(k+1));
		}
	printf("%I64d %I64d\n",sml-n,big-n);
	return 0;
}