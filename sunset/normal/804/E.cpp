#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline LL read()
{
	LL sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	int n = read();
	if( n % 4 > 1 ) return puts( "NO" ), 0;
	puts( "YES" );
	for( int i = n % 4 ; i < n ; i += 4 )
	{
		for( int j = 0 ; j < i ; j++ ) printf( "%d %d\n", j + 1, i + 1 );
		printf( "%d %d\n", i + 1, i + 2 );
		for( int j = i - 1 ; ~j ; j-- ) printf( "%d %d\n", j + 1, i + 2 );
		for( int j = 0 ; j < i ; j++ ) printf( "%d %d\n", j + 1, i + 3 );
		printf( "%d %d\n", i + 3, i + 4 );
		for( int j = i - 1 ; ~j ; j-- ) printf( "%d %d\n", j + 1, i + 4 );
		printf( "%d %d\n", i + 1, i + 4 );
		printf( "%d %d\n", i + 2, i + 3 );
		printf( "%d %d\n", i + 1, i + 3 );
		printf( "%d %d\n", i + 2, i + 4 );
	}
}