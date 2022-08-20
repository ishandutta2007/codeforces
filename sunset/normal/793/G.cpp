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
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

const int MAXN = 1000005;
const int MAXM = 2000005;
const int MAXV = 100005;
const int INF = 0x3f3f3f3f;

namespace Flow
{
	struct edge { int to, nxt, flow; } e[MAXM];

	int head[MAXN], S, T, e_cnt = 1, q[MAXN], ql, qr, dis[MAXN], cur[MAXN];

	inline void add(int x, int y, int w) { e[ ++e_cnt ] = { y, head[ x ], w }; head[ x ] = e_cnt; }
	inline void addedge(int x, int y, int w) { add( x, y, w ); add( y, x, 0 ); }

	inline bool bfs()
	{
		fill( dis, 0 ); dis[ q[ ql = 0 ] = S ] = qr = 1;
		while( ql ^ qr )
		{
			int x = q[ ql++ ];
			for( int i = head[ x ] ; i ; i = e[ i ].nxt ) if( e[ i ].flow && !dis[ e[ i ].to ] )
				dis[ q[ qr++ ] = e[ i ].to ] = dis[ x ] + 1;
		}
		return dis[ T ];
	}

	inline int dfs(int x, int f)
	{
		if( x == T ) return f;
		int ret = 0;
		for( int &i = cur[ x ] ; i ; i = e[ i ].nxt )
			if( e[ i ].flow && dis[ e[ i ].to ] == dis[ x ] + 1 )
			{
				int d = dfs( e[ i ].to, min( f - ret, e[ i ].flow ) );
				e[ i ].flow -= d; e[ i ^ 1 ].flow += d; ret += d;
				if( ret == f ) return ret;
			}
		if( !ret ) dis[ x ] = -1;
		return ret;
	}

	inline int dinic()
	{
		int ret = 0;
		while( bfs() ) copy( cur, head ), ret += dfs( S, INF );
		return ret;
	}
}

using Flow::S;
using Flow::T;
using Flow::dinic;
using Flow::addedge;

struct node { int ls, rs; } e[MAXV];
vector < pair< int, pa > > L, R;
int tot, n, m, rt1, rt2, tim[10005];

inline void build(int &x, int l, int r, bool type)
{
	x = ++tot;
	if( l == r )
	{
		if( type ) addedge( x, T, 1 );
		else addedge( S, x, 1 );
		return ;
	}
	int mid = l + r >> 1;
	build( e[ x ].ls, l, mid, type ); build( e[ x ].rs, mid + 1, r, type );
	if( type ) addedge( x, e[ x ].ls, INF ), addedge( x, e[ x ].rs, INF );
	else addedge( e[ x ].ls, x, INF ), addedge( e[ x ].rs, x, INF );
}

inline void modify(int x, int l, int r, int ql, int qr, bool type)
{
	if( l == ql && r == qr )
	{
		if( type ) addedge( tot, x, INF );
		else addedge( x, tot, INF );
		return ;
	}
	int mid = l + r >> 1;
	if( qr <= mid ) modify( e[ x ].ls, l, mid, ql, qr, type );
	else if( ql > mid ) modify( e[ x ].rs, mid + 1, r, ql, qr, type );
	else modify( e[ x ].ls, l, mid, ql, mid, type ), modify( e[ x ].rs, mid + 1, r, mid + 1, qr, type );
}

inline void ins(pa p, int t)
{
	for( int i = p.xx ; i <= p.yy ; i++ ) tim[ i ] = t;
}

inline void merge(int a, int b, int c, int d)
{
	if( a > b || c > d ) return ;
	tot++;
	modify( rt1, 1, n, a, b, 0 );
	modify( rt2, 1, n, c, d, 1 );
}

inline void del(pa p, int t)
{
	int a = -1, b = -1, lst = -1, c, d;
	for( int i = p.xx ; i <= p.yy ; i++ )
	{
		c = tim[ i ], d = t - 1;
		tim[ i ] = 0;
		if( a != c || b != d )
		{
			if( ~lst ) merge( a, b, lst, i - 1 );
			a = c, b = d, lst = i;
		}
	}
	if( ~lst ) merge( a, b, lst, p.yy );
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	n = read(), m = read(); T = tot = 1;
	build( rt1, 1, n, 0 ); build( rt2, 1, n, 1 );
	for( int i = 1 ; i <= m ; i++ )
	{
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		L.pb( mp( x1, mp( y1, y2 ) ) );
		R.pb( mp( x2 + 1, mp( y1, y2 ) ) );
	}
	sort( L.begin(), L.end() ); sort( R.begin(), R.end() );
	ins( mp( 1, n ), 1 );
	for( int i = 0, j = 0 ; i < m ; i++ )
	{
		while( j < m && R[ j ].xx <= L[ i ].xx ) ins( R[ j ].yy, R[ j ].xx ), j++;
		del( L[ i ].yy, L[ i ].xx );
		if( i == m - 1 ) while( j < m ) ins( R[ j ].yy, R[ j ].xx ), j++;
	}
	del( mp( 1, n ), n + 1 );
	return printf( "%d\n", dinic() ), 0;
}