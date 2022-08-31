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

int n, pw[61], bt[61], de[61], ed[61];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	while( n-- )
	{
		LL x = read(); int f = 1, c = 0;
		for( ; x ^ 1 ; x >>= 1, c++ ) if( x & 1 ) f = 0;
		if( f ) pw[ c ]++; else bt[ c ]++;
	}
	int L = 1, R = pw[ 0 ] + 1;
	while( L < R )
	{
		int mid = L + R >> 1, cur = mid, cnt = 0;
		for( int i = 0 ; i < 60 ; i++ )
		{
			de[ i ] = pw[ i ] - cur;
			ed[ i ] = cur - min( pw[ i + 1 ], cur );
			cur = min( pw[ i + 1 ], cur );
		}
		for( int i = 59 ; ~i ; i-- )
		{
			cnt = cnt + ed[ i ] - de[ i + 1 ] - bt[ i ];
			if( cnt < 0 ) goto GG;
		}
		if( cnt < de[ 0 ] ) goto GG;
		R = mid; continue;
GG:     L = mid + 1;
	}
	if( L > pw[ 0 ] ) puts( "-1" );
	else for( int i = L ; i <= pw[ 0 ] ; i++ ) printf( "%d%c", i, i == pw[ 1 ] ? '\n' : ' ' );
	return 0;
}