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

int a[6], b[6], n, cnt[6], x[6];

inline int cal(int *a, int *x, int n)
{
	int ret = 0;
	for( int i = 1, t ; i <= 5 ; i++ )
	{
		if( !~a[ i ] ) continue;
		if( ( n >> 5 ) >= x[ i ] ) t = 3000;
		else if( ( n >> 4 ) >= x[ i ] ) t = 2500;
		else if( ( n >> 3 ) >= x[ i ] ) t = 2000;
		else if( ( n >> 2 ) >= x[ i ] ) t = 1500;
		else if( ( n >> 1 ) >= x[ i ] ) t = 1000;
		else t = 500;
		ret += t - t / 250 * a[ i ];
	}
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= 5 ; i++ ) cnt[ i ] += ( ( a[ i ] = read() ) != -1 );
	for( int i = 1 ; i <= 5 ; i++ ) cnt[ i ] += ( ( b[ i ] = read() ) != -1 );
	for( int j = 1 ; j <= n - 2 ; j++ ) for( int i = 1 ; i <= 5 ; i++ ) cnt[ i ] += ( read() != -1 );  	
	for( int i = 0 ; i < 1e5 ; i++ )
	{
		for( int j = 1 ; j <= 5 ; j++ ) x[ j ] = cnt[ j ];
		for( int j = 1 ; j <= 5 ; j++ )
			if( ~a[ j ] && ~b[ j ] && a[ j ] > b[ j ] ) x[ j ] += i;
		if( cal( a, x, n + i ) > cal( b, x, n + i ) ) return printf( "%d\n", i ), 0;
	}
	return puts( "-1" ), 0;
}