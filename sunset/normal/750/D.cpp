#include <bits/stdc++.h>
#define mp( i, j ) vis[ i + 160 ][ j + 160 ]
#define dr( i, j, k ) dir[ i + 160 ][ j + 160 ][ k ]
#define us( i, j ) used[ i + 160 ][ j + 160 ]

using namespace std;

int vis[333][333],used[333][333], n, x;

int dx[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };

int dy[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };

set < int > dir[333][333][31];

int main()
{
	scanf( "%d", &n );
	mp( 0, 0 ) = us( 0, 0 ) = 1; dr( 0, 0, 1 ).insert( 3 );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d", &x );
		if( i == 1 ) x--;
		for( int j = -150 ; j <= 150 ; j++ )
			for( int k = -150 ; k <= 150 ; k++ )
				if( mp( j, k ) == i )
				{
					for( set< int >::iterator it = dr( j, k, i ).begin() ; it != dr( j, k, i).end() ; it++ )
					{
						for( int d = 1 ; d < x ; d++ )
							if( us( j + d * dx[ *it ], k + d * dy[ *it ] ) != i + 1 )
								us( j + d * dx[ *it ], k + d * dy[ *it ] ) = -1;
						us( j + x * dx[ *it ], k + x * dy[ *it ] ) = i + 1;
						dr( j + x * dx[ *it ], k + x * dy[ *it ], i + 1 ).insert( ( *it ) % 8 + 1 );
						dr( j + x * dx[ *it ], k + x * dy[ *it ], i + 1 ).insert( ( *it + 6 ) % 8 + 1 );
					}
				}
		memcpy( vis, used, sizeof( used ) );
	}
	int ans = 0;
	for( int i = -150 ; i <= 150 ; i++ )
		for( int j = -150; j <= 150 ; j++ )
			if( mp( i, j ) )
				ans++;
	cout << ans << endl;
}