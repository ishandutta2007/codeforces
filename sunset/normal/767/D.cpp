#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

const int MAXN = 1000001;
const int MAXM = 10000001;

int n, m, k, f[MAXM], cur, q[MAXN], top;

struct node
{
	int x, id;
	bool operator < ( const node &b ) const { return x < b.x; }
}e[MAXN];

int main()
{
	n = read(), m = read(), k = read();
	for( int i = 1 ; i <= n ; i++ )
		if( ++f[ read() ] > k )
			return puts( "-1" ), 0;
	for( int i = 1 ; i <= m ; i++ ) e[ i ].x = read(), e[ i ].id = i;
	sort( e + 1, e + m + 1 );
	for( int i = 1 ; i <= m ; i++ )
	{
		while( f[ cur ] == k ) cur++;
		if( cur <= e[ i ].x ) f[ cur ]++, q[ ++top ] = e[ i ].id;
	}
	printf( "%d\n", top );
	sort( q + 1, q + top + 1 );
	for( int i = 1 ; i <= top ; i++ ) printf( "%d ", q[ i ] ); 
}