#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;

int H, l[maxn], a[maxn][4], q[maxn], T, head, tail;

bool used[maxn];

inline void get(int x)
{
	if( used[ x ] ) return;
	printf( "? %d\n", x );
	fflush( stdout );
	used[ x ] = true;
	scanf( "%d", &l[ x ] );
	for( int i = 1 ; i <= l[ x ] ; i++ ) scanf( "%d", &a[ x ][ i ] );
}

inline void print(int x)
{
	printf( "! %d\n", x );
	fflush( stdout );
}

inline void solve()
{
	memset( used, 0, sizeof( used ) );
	scanf( "%d", &H );
	get( 1 );
	head = tail = 20;
	if( l[ 1 ] == 2 ) { print( 1 ); return ; }
	if( l[ 1 ] == 1 ) q[ 20 ] = 1;
	else
	{
		q[ 20 ] = 1;
		q[ ++tail ] = a[ 1 ][ 1 ];
		while( true )
		{
			get( q[ tail ] );
			if( l[ q[ tail ] ] == 1 ) break;
			for( int i = 1 ; i <= l[ q[ tail ] ] ; i++ )
				if( a[ q[ tail ] ][ i ] != q[ tail - 1 ] )
				{
					q[ tail + 1 ] = a[ q[ tail ] ][ i ];
					tail++;
					break;
				}
		}
		q[ --head ] = a[ 1 ][ 2 ];
		while( true )
		{
			get( q[ head ] );
			if( l[ q[ head ] ] == 1 ) break;
			for( int i = 1 ; i <= l[ q[ head ] ] ; i++ )
				if( a[ q[ head ] ][ i ] != q[ head + 1 ] )
				{
					q[ head - 1 ] = a[ q[ head ] ][ i ];
					head--;
					break;
				}
		}
	}
	int dep = H - ( tail - head ) / 2, cur = q[ head + tail >> 1 ];
	while( true )
	{
		if( dep <= 4 )
		{
			if( dep == 1 ) { print( cur ); return ; }
			for( int i = 1 ; i <= l[ cur ] ; i++ )
				if( !used[ a[ cur ][ i ] ] )
				{
					cur = a[ cur ][ i ];
					break;
				}
			dep--;
			if( dep == 1 ) { print( cur ); return ; }
			if( dep == 2 )
			{
				int tmp[20], len = 0;
				get( cur );
				for( int i = 1 ; i <= l[ cur ] ; i++ )
					if( !used[ a[ cur ][ i ] ] )
						tmp[ ++len ] = a[ cur ][ i ];
				for( int i = 1 ; i < len ; i++ )
				{
					get( tmp[ i ] );
					if( l[ tmp[ i ] ] == 2 ) { print( tmp[ i ] ); return ; }
				}
				print( tmp[ len ] ); return ;
			}
			else
			{
				int tmp[20], len = 0;
				int tmp2[20], len2 = 0;
				get( cur );
				for( int i = 1 ; i <= l[ cur ] ; i++ )
					if( !used[ a[ cur ][ i ] ] )
						tmp[ ++len ] = a[ cur ][ i ];
				for( int i = 1 ; i <= len ; i++ )
				{
					get( tmp[ i ] );
					for( int j = 1; j <= l[ tmp[ i ] ] ; j++ )
						if( !used[ a[ tmp[ i ] ][ j ] ] )
							tmp2[ ++len2 ] = a[ tmp[ i ] ][ j ];
				}
				for( int i = 1 ; i < len2 ; i++ )
				{
					get( tmp2[ i ] );
					if( l[ tmp2[ i ] ] == 2 ) { print( tmp2[ i ] ); return ; }
				}
				print( tmp2[ len2 ] ); return ;
			}
		}
		head = tail = 0;
		q[ tail ] = cur;
		while( true )
		{
			get( q[ tail ] );
			if( l[ q[ tail ] ] == 1 && tail > 0 ) break;
			if( l[ q[ tail ] ] == 2 ) { print( q[ tail ] ); return ; }
			for( int i = 1 ; i <= l[ q[ tail ] ] ; i++ )
				if( !used[ a[ q[ tail ] ][ i ] ] )
				{
					q[ tail + 1 ] = a[ q[ tail ] ][ i ];
					tail++;
					break;
				}
		}
		int D = H - dep;
		cur = q[ tail - D >> 1 ];
		dep -= ( tail - D >> 1 );
	}
}

int main()
{
	scanf( "%d", &T );
	while( T-- ) solve();
}