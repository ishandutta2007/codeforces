#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar(); }
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 500005;

int n, m, a[MAXN], b[MAXN];
priority_queue < LL > q1, q2;
LL ans;

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ] = read();
	for( int i = 1 ; i <= n ; i++ ) b[ i ] = read();
	int l = 0, r = 0x3f3f3f3f, ret;
	while( l <= r )
	{
		int mid = l + r >> 1, l_cnt = 0, r_cnt = 0; ans = 0;
		while( !q1.empty() ) q1.pop();
		while( !q2.empty() ) q2.pop();
		q2.push( -1e18 );
		for( int i = 1 ; i <= n ; i++ )
		{
			q1.push( mid - a[ i ] );
			LL v1 = b[ i ] - mid - q1.top(), v2 = b[ i ] - mid - q2.top();
			if( v1 < v2 && v1 < 0 ) ans += v1, l_cnt++, q1.pop(), q2.push( b[ i ] - mid );
			else if( v2 <= v1 && v2 < 0 ) ans += v2, q2.pop(), q2.push( b[ i ] - mid );
		}
		while( !q1.empty() ) q1.pop();
		while( !q2.empty() ) q2.pop();
		q2.push( -1e18 );
		for( int i = 1 ; i <= n ; i++ )
		{
			q1.push( mid - a[ i ] );
			LL v1 = b[ i ] - mid - q1.top(), v2 = b[ i ] - mid - q2.top();
			if( v1 <= v2 && v1 <= 0 ) r_cnt++, q1.pop(), q2.push( b[ i ] - mid );
			else if( v2 < v1 && v2 <= 0 ) q2.pop(), q2.push( b[ i ] - mid );
		}
		if( l_cnt <= m && r_cnt >= m ) return printf( "%lld\n", ans + 2LL * m * mid ), 0;
		if( r_cnt < m ) l = mid + 1; else r = mid - 1;
	}
}