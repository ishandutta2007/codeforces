#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300030;

pair < int, int > a[MAXN], b[MAXN];

priority_queue < int, vector < int >, greater < int > > q;

int n, ans, m, L, R, size;

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d%d", &a[ i ].first, &a[ i ].second );
		b[ i ] = a[ i ];
	}
	sort( a + 1, a + n + 1);
	for( int i = 1 ; i <= n ; i++ )
	{
		if( !size ) q.push( a[ i ].second ), size++;
		else
		{
			while( size && q.top() < a[ i ].first ) q.pop(), size--;
			q.push( a[ i ].second ); size++;
			while( size > m ) { q.pop(); size--; }
		}
		if( size == m )
		{
			if( q.top() - a[ i ].first + 1 > ans )
			{
				ans = q.top() - a[ i ].first + 1;
				L = a[ i ].first;
				R = q.top();
			}
		}
	}
	if( !ans )
	{
		printf( "%d\n", ans );
		for( int i = 1 ; i <= m ; i++ )
			printf( "%d ", i );
		putchar( 10 );
		return 0;
	}
	printf( "%d\n", ans );
	for( int i = 1 ; i <= n ; i++ )
		if( m && b[ i ].first <= L && b[ i ].second >= R )
			printf( "%d ", i ), m--;
	putchar( 10 );
	return 0;
}