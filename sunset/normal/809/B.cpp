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

char ch[5];

inline bool query(int x, int y)
{
	printf( "1 %d %d\n", x, y );
	fflush( stdout );
	scanf( "%s", ch );
	return ch[ 0 ] == 'T';
}

inline int solve(int l, int r)
{
	if( l > r ) return 0;
	while( l < r )
	{
		int mid = l + r >> 1;
		if( query( mid, mid + 1 ) ) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main()
{
#ifdef wxh010910
	//freopen( "data.in", "r", stdin );
#endif
	int n = read(); read();
	int x = solve( 1, n ), y = solve( 1, x - 1 );
	if( !y || !query( y, x ) ) y = solve( x + 1, n );
	return printf( "%d %d %d\n", 2, x, y ), 0;
}