// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	bool app[10]={};
	for ( int i=n; i; i/=10 ) app[i%10]=1;
	for ( int i=1; i*i<=n; i++ ) if ( n%i==0 ) {
		int d=i,f=0;
		while ( d ) {
			if ( app[d%10] ) f=1;
			d/=10;
		}
		if ( f ) ans++;
		if ( i*i==n ) continue;
		d=n/i; f=0;
		while ( d ) {
			if ( app[d%10] ) f=1;
			d/=10;
		}
		if ( f ) ans++;
	}
	printf("%d\n",ans);
	return 0;
}