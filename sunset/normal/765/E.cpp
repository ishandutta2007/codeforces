#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;

struct edge
{
	int to, nxt;
}e[MAXN << 1];

int n, d[MAXN], dl[MAXN], dr[MAXN], head[MAXN], cnt, ans, l, r, rt;

inline void add(int x, int y) { e[ ++cnt ].to = y; e[ cnt ].nxt = head[ x ]; head[ x ] = cnt; }
inline void addedge(int x, int y) { add( x, y ); add( y, x ); }

inline int dfs(int x, int fa, int dep, int *d)
{
	d[ x ] = dep;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( e[ i ].to ^ fa )
			dfs( e[ i ].to, x, dep + 1, d );
}

inline int solve(int x, int fa)
{
	vector < int > v;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( e[ i ].to ^ fa )
			v.push_back( solve( e[ i ].to, x ) );
	sort( v.begin(), v.end() );
	v.resize( unique( v.begin(), v.end() ) - v.begin() );
	if( x ^ fa )
	{
		if( v.size() > 1 )
			puts( "-1" ), exit( 0 );
		if( v.empty() ) return 1;
		return v[ 0 ] + 1;
	}
	if( v.size() > 2 ) return -1;
	return v[ 0 ] + v[ v.size() - 1 ];
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i < n ; i++ )
	{
		int u, v;
		scanf( "%d%d", &u, &v );
		addedge( u, v );
	}
	dfs( 1, 0, 0, d );
	for( int i = 1 ; i <= n ; i++ ) if( d[ i ] > d[ l ] ) l = i;
	dfs( l, 0, 0, dl );
	for( int i = 1 ; i <= n ; i++ ) if( dl[ i ] > dl[ r ] ) r = i;
	dfs( r, 0, 0, dr );
	rt = l;
	for( int i = 1 ; i <= n ; i++ )
		if( dl[ i ] + dr[ i ] == dl[ r ] && min( dl[ i ], dr[ i ] ) > min( dl[ rt ], dr[ rt ] ) ) rt = i;
	ans = solve( rt, rt );
	while( ans && !( ans & 1 ) ) ans >>= 1;
	cout << ans << endl;
}