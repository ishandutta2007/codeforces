#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

inline int cal(int x, int y, int z) { return x * 26 * 26 + y * 26 + z; }

struct node
{
	int c[4], id, type, val;
	bool operator < ( const node &b ) const { return val < b.val; }
}p[MAXN];

bool cmp(node a, node b) { return a.id < b.id; }

char ch[30];
int n, q[MAXN], ql, qr;

inline void print(int x)
{
	int a = x / 26 / 26;
	int b = x / 26 % 26;
	int c = x % 26;
	putchar( a + 'A' ); putchar( b + 'A' ); putchar( c + 'A' ); putchar( 10 );
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%s", ch );
		for( int j = 0 ; j < 3 ; j++ )
			p[ i ].c[ j ] = ch[ j ] - 'A';
		scanf( "%s", ch );
		p[ i ].c[ 3 ] = ch[ 0 ] - 'A';
		p[ i ].id = i; p[ i ].val = cal( p[ i ].c[ 0 ], p[ i ].c[ 1 ], p[ i ].c[ 2 ] );
	}
	sort( p + 1, p + n + 1 );
	for( int i = 1 ; i <= n ; i++ )
	{
		int l = i, r = i;
		while( r < n && p[ r + 1 ].val == p[ l ].val ) r++;
		if( l ^ r )
		{
			for( int j = l ; j <= r ; j++ )
				p[ j ].type = 1, p[ j ].val = cal( p[ j ].c[ 0 ], p[ j ].c[ 1 ], p[ j ].c[ 3 ] ), q[ ++qr ] = j;
			i = r;
		}
	}
	while( ql ^ qr )
	{
		int x = q[ ++ql ];
		for( int i = 1 ; i <= n ; i++ )
			if( p[ i ].val == p[ x ].val && i != x )
			{
				if( p[ i ].type ) return puts( "NO" ), 0;
				p[ i ].type = 1; p[ i ].val = cal( p[ i ].c[ 0 ], p[ i ].c[ 1 ], p[ i ].c[ 3 ] ), q[ ++qr ] = i;
			}
	}
	puts( "YES" );
	sort( p + 1, p + n + 1, cmp );
	for( int i = 1 ; i <= n ; i++ )
		print( p[ i ].val );
}