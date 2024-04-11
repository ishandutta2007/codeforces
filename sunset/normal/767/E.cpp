#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > pa;

const int MAXN = 100010;

priority_queue < pa > q;
int n, p[MAXN], c[MAXN], w[MAXN];
long long ans;
bool chk[MAXN];

inline int cal(int x) { x %= 100; if( !x ) return 0; return 100 - x; }

int main()
{
	scanf( "%d%d", &n, &p[ 0 ] );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &c[ i ] );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &w[ i ] );
	for( int i = 1 ; i <= n ; i++ ) p[ i ] = p[ i - 1 ] + cal( c[ i ] ), ans += cal( c[ i ] ) * w[ i ];
	for( int i = p[ n ] / 100, now = n, cnt = 0 ; i && cnt <= n ; )
	{
		while( now && p[ now ] >= i * 100 ) q.push( make_pair( cal( c[ now ] ) * w[ now ], now ) ), now--;
		if( !q.empty() )
		{
			ans -= q.top().first;
			chk[ q.top().second ] = 1;
			q.pop();
			i--; cnt++;
		}
		else
		{
			if( now ) i = p[ now ] / 100;
			else i--;
		}
	}
	printf( "%I64d\n", ans );
	for( int i = 1 ; i <= n ; i++ )
	{
		if( chk[ i ] ) printf( "%d %d\n", c[ i ] / 100, c[ i ] % 100 );
		else printf( "%d 0\n", ( c[ i ] + 99 ) / 100 );
	}
}