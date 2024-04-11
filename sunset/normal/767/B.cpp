#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

long long a[MAXN], S, T, t, n, ans, mx = 1e16;

int main()
{
	scanf( "%I64d%I64d%I64d", &S, &T, &t );
	scanf( "%I64d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%I64d", &a[ i ] );
	long long cur = S, l = 1;
	while( l <= n && a[ l ] <= cur ) cur += t, l++;
	if( cur + t <= T ) return cout << cur << endl, 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		if( a[ i ] == a[ i - 1 ] ) continue;
		long long st = a[ i ] - 1;
		if( st < 0 ) continue;
		long long ed = S + t * i;
		if( ed > T ) break;
		if( ed - st < mx ) mx = ed - st, ans = st;
	}
	cout << ans << endl;
}