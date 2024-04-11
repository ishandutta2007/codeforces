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

const int MAXN = 405;
const int INF = INT_MAX;

int ans = INF, c[MAXN], n;

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &c[ i ] );
	for( int i = 2 ; i <= n ; i++ )
		for( int j = i ; j <= n ; j++ )
		{
			int x = c[ i - 1 ] - 1, cnt = 0, t;
			for( int k = i ; k <= j ; k++ )
				cnt += x / c[ k ], x %= c[ k ];
			cnt++;
			t = x = c[ i - 1 ] - 1 - x + c[ j ];
			if( t < ans )
			{
				for( int k = 1 ; k <= n ; k++ )
					cnt -= x / c[ k ], x %= c[ k ];
				if( cnt < 0 ) ans = t;
			}
		}
	if( ans == INF ) ans = -1;
	cout << ans << endl;
}