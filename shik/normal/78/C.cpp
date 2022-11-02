// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int k;
bool go( int n, int m ) {
	if ( n%2==0 || m==1 ) return 0;
	for ( int i=1; i*i<=m; i++ ) if ( m%i==0 ) {
		if ( i>=k && !go(m/i,i) ) return 1;
		if ( i!=1 && m/i>=k && !go(i,m/i) ) return 1;
	}
	return 0;
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	puts(go(n,m)?"Timur":"Marsel");
	return 0;
}