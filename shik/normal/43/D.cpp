// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if ( n*m==2 ) {
		printf("0\n1 1\n%d %d\n1 1\n",n,m);
	} else if ( n==1 ) {
		printf("1\n1 %d 1 1\n",m);
		for ( int i=1; i<=m; i++ ) printf("1 %d\n",i);
		puts("1 1");
	} else if ( m==1 ) {
		printf("1\n%d 1 1 1\n",n);
		for ( int i=1; i<=n; i++ ) printf("%d 1\n",i);
		puts("1 1");
	} else if ( n%2==0 ) {
		puts("0\n1 1");
		for ( int i=1; i<=n; i++ ) {
			if ( i%2==1 ) for ( int j=2; j<=m; j++ ) printf("%d %d\n",i,j);
			else for ( int j=m; j>=2; j-- ) printf("%d %d\n",i,j);
		}
		for ( int i=n; i>=1; i-- ) printf("%d 1\n",i);
	} else if ( m%2==0 ) {
		puts("0\n1 1");
		for ( int i=1; i<=m; i++ ) {
			if ( i%2==1 ) for ( int j=2; j<=n; j++ ) printf("%d %d\n",j,i);
			else for ( int j=n; j>=2; j-- ) printf("%d %d\n",j,i);
		}
		for ( int i=m; i>=1; i-- ) printf("1 %d\n",i);
	} else {
		printf("1\n%d %d 1 1\n",n,m);
		for ( int i=1; i<=n; i++ ) {
			if ( i%2==1 ) for ( int j=1; j<=m; j++ ) printf("%d %d\n",i,j);
			else for ( int j=m; j>=1; j-- ) printf("%d %d\n",i,j);
		}
		puts("1 1");
	}
	return 0;
}