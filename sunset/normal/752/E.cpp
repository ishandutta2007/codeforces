#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000;

int a[maxn + 1], n, m, mx;

long long cnt[maxn * 10 + 1], cur;

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] ), cur += a[ i ], cnt[ a[ i ] ]++, mx = max( mx, a[ i ] );
	if( cur < m ) return puts( "-1" ), 0;
	cur = 0;
	for( int i = mx ; i ; i-- )
	{
		cur += cnt[ i ];
		if( i * 2 <= mx ) cur -= cnt[ i << 1 ];
		if( i * 2 - 1 <= mx && i != 1 ) cur -= cnt[ i * 2 - 1 ];
		if( cur >= m ) return printf( "%d\n", i ), 0;
		cnt[ i >> 1 ] += cnt[ i ];
		cnt[ i + 1 >> 1 ] += cnt[ i ];
	}
}