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

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	int n = read(), t = read(), k = read(), d = read();
	int t1 = ( n + k - 1 ) / k * t, cur = ( t1 - 1 ) / t * k + ( t1 - d - 1 ) / t * k;
	if( cur >= n ) return puts( "YES" ), 0;
	return puts( "NO" ), 0;
}