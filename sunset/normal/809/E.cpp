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

const int MAXN = 200005;
const int mod = 1e9 + 7;

vector < int > G[MAXN], fac[MAXN];
int n, phi[MAXN], f[MAXN], g[MAXN], h[MAXN], size[MAXN], p[MAXN], p_cnt, w[MAXN], ans, inv[MAXN], st[MAXN], top;
bool vis[MAXN];

inline void inc(int &x, int y) { x += y; if( x >= mod ) x -= mod; }
inline void dec(int &x, int y) { x -= y; if( x < 0 ) x += mod; }

inline void init()
{
	for( int i = 1 ; i <= n ; i++ ) for( int j = i ; j <= n ; j += i ) fac[ j ].pb( i );
	phi[ 1 ] = inv[ 1 ] = 1;
	for( int i = 2 ; i <= n ; i++ )
	{
		if( !phi[ i ] ) phi[ p[ ++p_cnt ] = i ] = i - 1;
		for( int j = 1 ; i * p[ j ] <= n ; j++ )
		{
			if( i % p[ j ] ) phi[ i * p[ j ] ] = phi[ i ] * ( p[ j ] - 1 );
			else { phi[ i * p[ j ] ] = phi[ i ] * p[ j ]; break; }
		}
	}
	for( int i = 2 ; i <= n ; i++ ) inv[ i ] = 1LL * ( mod - mod / i ) * inv[ mod % i ] % mod;
	for( int i = 1 ; i <= n ; i++ )
	{
		f[ i ] = 1LL * i * inv[ phi[ i ] ] % mod;
		for( auto j : fac[ i ] ) if( i ^ j ) dec( f[ i ], f[ j ] );
	}
}

inline void findroot(int x, int fa, int Size, int &cg)
{
	size[ x ] = 1;
	bool flag = true;
	for( auto y : G[ x ] ) if( !vis[ y ] ) if( y ^ fa )
		findroot( y, x, Size, cg ), flag &= size[ y ] <= ( Size >> 1 ), size[ x ] += size[ y ];
	flag &= size[ x ] >= ( Size >> 1 );
	if( flag ) cg = x;
}

inline void dfs(int x, int fa)
{
	size[ x ] = 1;
	for( auto y : G[ x ] ) if( !vis[ y ] ) if( y ^ fa )
		dfs( y, x ), size[ x ] += size[ y ];
}

inline void push(int x, int y, int z)
{
	if( !~g[ x ] ) st[ ++top ] = x, g[ x ] = h[ x ] = 0;
	inc( g[ x ], 1LL * f[ x ] * y % mod );
	inc( h[ x ], 1LL * f[ x ] * z % mod );
}

inline void get(int x, int &y, int &z)
{
	if( !~g[ x ] ) y = z = 0;
	else y = g[ x ], z = h[ x ];
}

inline void cal(int x, int fa, int dis)
{
	int a = phi[ w[ x ] ], b = 1LL * dis * a % mod, A, B;
	for( auto i : fac[ w[ x ] ] ) get( i, A, B ), inc( ans, 1LL * a * B % mod ), inc( ans, 1LL * b * A % mod );
	for( auto y : G[ x ] ) if( !vis[ y ] ) if( y ^ fa ) cal( y, x, dis + 1 );
}

inline void ins(int x, int fa, int dis)
{
	int a = phi[ w[ x ] ], b = 1LL * dis * a % mod;
	for( auto i : fac[ w[ x ] ] ) push( i, a, b );
	for( auto y : G[ x ] ) if( !vis[ y ] ) if( y ^ fa ) ins( y, x, dis + 1 );
}

inline void solve(int x, int Size)
{
	int cg;
	findroot( x, 0, Size, cg );
	vis[ x = cg ] = 1;
	dfs( x, 0 );
	for( auto i : fac[ w[ x ] ] ) push( i, phi[ w[ x ] ], 0 );
	for( auto y : G[ x ] ) if( !vis[ y ] ) cal( y, x, 1 ), ins( y, x, 1 );
	while( top ) g[ st[ top ] ] = h[ st[ top ] ] = -1, top--;
	for( auto y : G[ x ] ) if( !vis[ y ] ) solve( y, size[ y ] );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read();
	for( int i = 1 ; i <= n ; i++ ) w[ i ] = read();
	for( int i = 1, x, y ; i < n ; i++ ) x = read(), y = read(), G[ x ].pb( y ), G[ y ].pb( x );
	init();
	fill( g, -1 ); fill( h, -1 );
	solve( 1, n );
	ans = 2LL * ans * inv[ n ] % mod * inv[ n - 1 ] % mod;
	return printf( "%d\n", ans ), 0;
}