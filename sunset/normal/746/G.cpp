#include <bits/stdc++.h>

using namespace std;

const int maxn = 200020;

int cur, cnt, l[maxn], r[maxn], f[maxn], n, t, k, a[maxn];

int now, L[maxn];

int main()
{
	scanf( "%d%d%d", &n, &t, &k );
	l[ 0 ] = r[ 0 ] = 1;
	L[ 0 ] = 2;
	for( int i = 1 ; i <= t ; i++ )
	{
		scanf( "%d",&a[ i ] );
		l[ i ] = r[ i - 1 ] + 1;
		L[ i ] = l[ i ] + 1;
		r[ i ] = l[ i ] + a[ i ] - 1;
		for( int j = l[ i ] ; j <= r[ i ] ; j++ )
		{
			f[ j ] = l[ i - 1 ];
			if( j != l[ i ] || i == t ) cnt++ ;
		}
	}
	if( cnt < k ) return puts("-1"), 0;
	int ret = t, now = l[ ret ] + 1;
	while( cnt > k )
	{
		if( !ret ) return puts("-1"),0;
		if( L[ ret - 1 ] == r[ ret - 1 ] + 1 ) { now = l[ --ret ] + 1; continue; }
		if( now == r[ ret ] + 1 ) { now = l[ --ret ] + 1; continue; }
		f[ now ] = L[ ret - 1 ];
		cnt--;
		now++;
		L[ ret - 1 ]++;
	}
	printf("%d\n",n);
	for( int i = 2 ; i <= n ; i++ )
		printf( "%d %d\n",i,f[ i ] );
	return 0;
}