#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int MAXM = MAXN * 30;
const int MAXF = 10010;
const int INF = 1e9;

inline int read()
{
	int sc = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) sc = sc * 10 + ch - '0', ch = getchar();
	return sc;
}

int ls[MAXM], rs[MAXM], v[MAXM], root[MAXF], n, m, rank[MAXN], tot;

long long ans;

struct node
{
	int x, r, f;
	bool operator < ( const node & b ) const { return x < b.x; }
}a[MAXN];

bool cmp(int x, int y) { return a[ x ].x + a[ x ].r < a[ y ].x + a[ y ].r; }

inline void modify(int &x, int l, int r, int pos, int val)
{
	if( !x ) x = ++tot;
	v[ x ] += val;
	if( l == r ) return ;
	int mid = l + r >> 1;
	if( pos <= mid ) modify( ls[ x ], l, mid, pos, val );
	else modify( rs[ x ], mid + 1, r, pos, val );
}

inline int query(int x, int l, int r, int pos)
{
	if( !x ) return 0;
	if( l >= pos ) return v[ x ];
	int mid = l + r >> 1;
	if( pos <= mid ) return query( ls[ x ], l, mid, pos ) + v[ rs[ x ] ];
	return query( rs[ x ], mid + 1, r, pos );
}

int main()
{
	n = read(), m = read();
	for( int i = 1 ; i <= n ; i++ ) a[ i ].x = read(), a[ i ].r = read(), a[ i ].f = read(), rank[ i ] = i;
	sort( a + 1, a + n + 1 ); sort( rank + 1, rank + n + 1, cmp );
	for( int i = 1, j = 1 ; i <= n ; i++ )
	{
		while( j <= n && a[ rank[ j ] ].x + a[ rank[ j ] ].r < a[ i ].x ) modify( root[ a[ rank[ j ] ].f ], 1, INF, a[ rank[ j ] ].x, -1 ), j++;
		for( int k = max( 1, a[ i ].f - m ) ; k <= min( 10000, a[ i ].f + m ) ; k++ ) ans += query( root[ k ], 1, INF, max( a[ i ].x - a[ i ].r , 1 ) );
		modify( root[ a[ i ].f ], 1, INF, a[ i ].x, 1 );
	}
	cout << ans << endl;
	return 0;
}