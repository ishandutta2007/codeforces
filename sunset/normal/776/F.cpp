#include <bits/stdc++.h>
#define xx first
#define yy second
using namespace std;

typedef pair < int, int > pa;
typedef set < int > :: iterator It;

const int MAXN = 100010;

struct edge{ int to, nxt; }e[MAXN << 1];

set < int > S;
vector < int > v[MAXN];
pa p[MAXN];
map < pa, int > mp;
int n, m, ans[MAXN], head[MAXN], cnt, tot, size[MAXN];
bool vis[MAXN];

inline void add(int x, int y) { e[ ++cnt ] = ( edge ){ y, head[ x ] }; head[ x ] = cnt; }
inline void addedge(int x, int y) { add( x, y ); add( y, x ); }

bool cmp(pa a, pa b)
{
	 int x = min( a.yy - a.xx - 1, n - 2 - ( a.yy - a.xx - 1 ) );
	 int y = min( b.yy - b.xx - 1, n - 2 - ( b.yy - b.xx - 1 ) );
	 return x < y;
}

inline void findroot(int x, int fa, int Size, int &cg)
{
	bool flag = true;
	size[ x ] = 1;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( !vis[ e[ i ].to ] && e[ i ].to != fa )
		{
			findroot( e[ i ].to, x, Size, cg );
			if( ( size[ e[ i ].to ] << 1 ) > Size ) flag = false;
			size[ x ] += size[ e[ i ].to ];
		}
	if( ( size[ x ] << 1 ) < Size ) flag = false;
	if( flag ) cg = x;
	return ;
}

inline void dfs(int x, int fa)
{
	size[ x ] = 1;
	for( int i = head[ x ] ; i ; i = e[ i ].nxt )
		if( !vis[ e[ i ].to ] && e[ i ].to != fa )
			dfs( e[ i ].to, x ), size[ x ] += size[ e[ i ].to ];
}

inline void solve(int x, int Size, int dep)
{
	int cg;
	findroot( x, 0, Size, cg );
	ans[ cg ] = dep; vis[ cg ] = 1;
	dfs( cg, 0 );
	for( int i = head[ cg ] ; i ; i = e[ i ].nxt )
		if( !vis[ e[ i ].to ] )
			solve( e[ i ].to, size[ e[ i ].to ], dep + 1 );
}

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 1 ; i <= m ; i++ )
	{
		scanf( "%d%d", &p[ i ].xx, &p[ i ].yy );
		if( p[ i ].xx > p[ i ].yy ) swap( p[ i ].xx, p[ i ].yy );
	}
	sort( p + 1, p + m + 1, cmp );
	for( int i = 1 ; i <= n ; i++ ) S.insert( i );
	for( int i = 1 ; i <= m ; i++ )
	{
		tot++;
		if( p[ i ].yy - p[ i ].xx - 1 <= ( n - 2 >> 1 ) )
		{
			v[ tot ].push_back( p[ i ].xx );
			It it = S.upper_bound( p[ i ].xx );
			while( ( *it ) ^ p[ i ].yy )
			{
				v[ tot ].push_back( *it );
				it++;
			}
			v[ tot ].push_back( p[ i ].yy );
			for( int j = 1 ; j < v[ tot ].size() - 1; j++ )
				S.erase( v[ tot ][ j ] );
		}
		else
		{
			while( ( *S.begin() ) ^ p[ i ].xx )
			{
				v[ tot ].push_back( *S.begin() );
				S.erase( S.begin() );
			}
			v[ tot ].push_back( p[ i ].xx );
			v[ tot ].push_back( p[ i ].yy );
			int l = v[ tot ].size();
			It it = S.upper_bound( p[ i ].yy );
			while( it != S.end() )
			{
				v[ tot ].push_back( *it );
				it++;
			}
			for( ; l < v[ tot ].size() ; l++ ) S.erase( v[ tot ][ l ] );
		}
		reverse( v[ tot ].begin(), v[ tot ].end() );
	}
	tot++;
	while( !S.empty() )
	{
		v[ tot ].push_back( *S.begin() );
		S.erase( S.begin() );
	}
	reverse( v[ tot ].begin(), v[ tot ].end() );
	sort( v + 1, v + tot + 1 );
	for( int i = 1 ; i <= tot ; i++ )
	{
		int sz = v[ i ].size() - 1;
		for( int j = 0 ; j < sz ; j++ )
		{
			if( v[ i ][ j ] == v[ i ][ j + 1 ] + 1 ) continue;
			if( mp.find( make_pair( v[ i ][ j ], v[ i ][ j + 1 ] ) ) == mp.end() )
				mp[ make_pair( v[ i ][ j ], v[ i ][ j + 1 ] ) ] = i;
			else
				addedge( mp[ make_pair( v[ i ][ j ], v[ i ][ j + 1 ] ) ], i ), mp.erase( make_pair( v[ i ][ j ], v[ i ][ j + 1 ] ) );
		}
		if( v[ i ][ sz ] != 1 || v[ i ][ 0 ] != n )
		{
			if( mp.find( make_pair( v[ i ][ 0 ], v[ i ][ sz ] ) ) == mp.end() )
				mp[ make_pair( v[ i ][ 0 ], v[ i ][ sz ] ) ] = i;
			else
				addedge( mp[ make_pair( v[ i ][ 0 ], v[ i ][ sz ] ) ], i ),mp.erase( make_pair( v[ i ][ 0 ], v[ i ][ sz ] ) );
		}
	}
	solve( 1, tot, 1 );
	for( int i = 1 ; i <= tot ; i++ ) printf( "%d ", ans[ i ] );
}