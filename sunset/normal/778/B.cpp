#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MAXM = 1001;

map < string, int > mp;
string s[MAXN], tmp;
int n, m, a[MAXN][2], type[MAXN], b[MAXN][MAXM];
int cur[MAXN][ 2 ], mx[MAXM], mn[MAXM];

int main()
{
	scanf( "%d%d\n", &n, &m );
	for( int i = 1 ; i <= n ; i++ )
		getline( cin, s[ i ] );
	mp[ "?" ] = n + 1;
	for( int i = 1 ; i <= n ; i++ )
	{
		int j;
		string tmp = "";
		for( j = 0 ; s[ i ][ j ] != ' ' ; j++ )
			tmp += s[ i ][ j ];
		mp[ tmp ] = i;
		for( j++ ; s[ i ][ j ] != ' ' ; j++ ); j++;
		if( s[ i ][ j ] != '0' && s[ i ][ j ] != '1' )
		{
			tmp = "";
			for( ; s[ i ][ j ] != ' ' ; j++ )
				tmp += s[ i ][ j ];
			a[ i ][ 0 ] = mp[ tmp ];
			j++;
			if( s[ i ][ j ] == 'A' ) type[ i ] = 1;
			else if( s[ i ][ j ] == 'O' ) type[ i ] = 2;
			else type[ i ] = 3;
			for( ; s[ i ][ j ] != ' ' ; j++ );
			tmp = "";
			for( j++ ; s[ i ][ j ] ; j++ )
				tmp += s[ i ][ j ];
			a[ i ][ 1 ] = mp[ tmp ];
		}
		else
		{
			type[ i ] = 0;
			for( int now = 1 ; now <= m ; now++, j++ )
				b[ i ][ now ] = s[ i ][ j ] - '0';
		}
	}
	for( int bit = 1 ; bit <= m ; bit++ )
	{
		int ans0 = 0, ans1 = 0;
		cur[ n + 1 ][ 1 ] = 1;
		cur[ n + 1 ][ 0 ] = 0;
		for( int i = 1 ; i <= n ; i++ )
		{
			if( !type[ i ] ) cur[ i ][ 0 ] = cur[ i ][ 1 ] = b[ i ][ bit ];
			else if( type[ i ] == 1 ) cur[ i ][ 0 ] = cur[ a[ i ][ 0 ] ][ 0 ] & cur[ a[ i ][ 1 ] ][ 0 ], ans0 += cur[ i ][ 0 ],
									  cur[ i ][ 1 ] = cur[ a[ i ][ 0 ] ][ 1 ] & cur[ a[ i ][ 1 ] ][ 1 ], ans1 += cur[ i ][ 1 ];
			else if( type[ i ] == 2 ) cur[ i ][ 0 ] = cur[ a[ i ][ 0 ] ][ 0 ] | cur[ a[ i ][ 1 ] ][ 0 ], ans0 += cur[ i ][ 0 ],
									  cur[ i ][ 1 ] = cur[ a[ i ][ 0 ] ][ 1 ] | cur[ a[ i ][ 1 ] ][ 1 ], ans1 += cur[ i ][ 1 ];
			else if( type[ i ] == 3 ) cur[ i ][ 0 ] = cur[ a[ i ][ 0 ] ][ 0 ] ^ cur[ a[ i ][ 1 ] ][ 0 ], ans0 += cur[ i ][ 0 ],
									  cur[ i ][ 1 ] = cur[ a[ i ][ 0 ] ][ 1 ] ^ cur[ a[ i ][ 1 ] ][ 1 ], ans1 += cur[ i ][ 1 ];

		}
		if( ans0 > ans1 ) mx[ bit ] = 0, mn[ bit ] = 1;
		else if( ans0 < ans1 ) mx[ bit ] = 1, mn[ bit ] = 0;
		else mx[ bit ] = mn[ bit ] = 0;
	}
	for( int i = 1 ; i <= m ; i++ ) putchar( mn[ i ] + '0' ); putchar( 10 );
	for( int i = 1 ; i <= m ; i++ ) putchar( mx[ i ] + '0' ); putchar( 10 );
}