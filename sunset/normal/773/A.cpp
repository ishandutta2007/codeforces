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

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	for( int T = read() ; T ; T-- )
	{
		int x = read(), y = read(), p = read(), q = read();
		if( !p ) { puts( x ? "-1" : "0" ); continue; }
		if( p == q ) { puts( x == y ? "0" : "-1" ); continue; }
		LL t = max( ( x + p - 1 ) / p, ( y - x + q - p - 1 ) / ( q - p ) );
		printf( "%lld\n", t * q - y );
	}
}