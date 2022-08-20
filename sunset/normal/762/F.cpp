#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
const int MAXV = 1 << 12;
const int mod = 1e9 + 7;

inline int Pow(int x, int y)
{
	int s = 1;
	for( ; y ; y >>= 1, x = 1ll * x * x % mod ) if( y & 1 ) s = 1ll * s * x % mod;
	return s;
}

inline int inv(int x) { return Pow( x, mod - 2 ); }

struct edge { int to, nxt; };

struct tree
{
	edge e[MAXN << 1];
	int n, cnt;
	int head[MAXN], son[MAXN][MAXN], size[MAXN], bit[MAXN];
	inline void addedge(int x, int y) { e[ ++cnt ].to = y; e[ cnt ].nxt = head[ x ]; head[ x ] = cnt; }
	inline void read()
	{
		scanf( "%d", &n );
		for( int i = 1 ; i < n ; i++ ) { int x, y; scanf( "%d%d", &x, &y ); addedge( x, y ); addedge( y, x ); }
	}
	inline void dfs(int x, int fa)
	{
		size[ x ] = bit[ x ] = 0;
		for( int i = head[ x ] ; i ; i = e[ i ].nxt ) if( e[ i ].to ^ fa )
			dfs( son[ x ][ ++size[ x ] ] = e[ i ].to, x ), bit[ x ] |= 1 << e[ i ].to - 1; 
	}
}S, T;

int dp[MAXN][MAXV], ans, ans2;

bool vis[MAXN][MAXV];

inline int dfs(int f, int y, int V)
{
	if( !y ) return !V;
	int x = S.son[ f ][ y ];
	if( vis[ x ][ V ] ) return dp[ x ][ V ];
	vis[ x ][ V ] = 1;
	int &ret = dp[ x ][ V ];
	ret = dfs( f, y - 1, V );
	for(int i = 0 ; i < T.n ; i++ ) if( V >> i & 1 )
		ret = ( 1ll * dfs( f, y - 1, V ^ ( 1 << i ) ) * dfs( x, S.size[ x ], T.bit[ i + 1 ] ) + ret ) % mod;
	return ret; 
}

int main()
{
	S.read();
	T.read();
	S.dfs( 1, 0 );
	for( int i = 1 ; i <= T.n ; i++ )
	{
		memset( dp, 0, sizeof dp );
		memset( vis, 0, sizeof vis );
		T.dfs( i, 0 );
		for( int j = 1 ; j <= S.n ; j++ ) ( ans += dfs( j, S.size[ j ], T.bit[ i ] ) ) %= mod;
	}
	S = T;
	S.dfs( 1, 0 );
	for( int i = 1 ; i <= T.n ; i++ )
	{
		memset( dp, 0, sizeof dp );
		memset( vis, 0, sizeof vis );
		T.dfs( i, 0 );
		( ans2 += dfs( 1, S.size[ 1 ], T.bit[ i ] ) ) %= mod;
	}
	ans = 1ll * ans * inv( ans2 ) % mod;
	return printf( "%d\n", ans ), 0;
}