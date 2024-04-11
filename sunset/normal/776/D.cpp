#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;

vector < int > a[MAXN];
int f[MAXN], n, m, b[MAXN];

inline int findfa(int x) { while( x ^ f[ x ] ) x = f[ x ] = f[ f[ x ] ]; return x; }

int main()
{
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &b[ i ] );
	for( int i = 1 ; i <= 2 * m ; i++ ) f[ i ] = i;
	for( int i = 1 ; i <= m ; i++ )
	{
		int x, t;
		scanf( "%d", &x );
		while( x-- )
		{
			scanf( "%d", &t );
			a[ t ].push_back( i );
		}
	}
	bool flag = true;
	for( int i = 1 ; i <= n ; i++ )
	{
		int x = a[ i ][ 0 ], y = a[ i ][ 1 ];
		if( b[ i ] )
		{
			if( findfa( x ) == findfa( y + m ) ) flag = false;
			else f[ findfa( x ) ] = findfa( y ),
				f[ findfa( y + m ) ] = findfa( x + m );
		}
		else
		{
			if( findfa( x ) == findfa( y ) ) flag = false;
			else f[ findfa( x ) ] = findfa( y + m ),
				f[ findfa( y ) ] = findfa( x + m );
		}
	}
	if( flag ) cout << "YES" << endl;
	else cout << "NO" << endl;
}