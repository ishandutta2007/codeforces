#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
const int MAXN = 55;
int _w;

int n, s, m, x[MAXN];
int ss[680];

namespace Tree {
	int head[MAXN], nxt[MAXN<<1], to[MAXN<<1], len[MAXN<<1], eidx;
	void init() {
		memset(head, -1, sizeof head);
	}
	void adde( int u, int v, int w ) {
		to[eidx] = v, len[eidx] = w;
		nxt[eidx] = head[u], head[u] = eidx++;
		to[eidx] = u, len[eidx] = w;
		nxt[eidx] = head[v], head[v] = eidx++;
	}
}

bool leaf[MAXN];
void prelude() {
	using namespace Tree;
	for( int u = 1; u <= n; ++u ) {
		int d = 0;
		for( int i = head[u]; ~i; i = nxt[i] )
			++d;
		leaf[u] = d == 1;
	}
}

int f[MAXN<<1][MAXN][MAXN], g[MAXN];
int knapsack( int e, int m, int k );
int dp( int e, int m, int k ) {
	using namespace Tree;
	int &now = f[e][m][k];
	if( now != -1 ) return now;
	if( !m ) return now = 0;
	if( leaf[to[e]] ) now = dp(e^1, m-k, m-k) + len[e];
	else now = knapsack(e, m, k) + len[e];
	// printf( "dp: f[%d, %d][%d][%d] = %d\n", to[e^1], to[e], m, k, now );
	return now;
}
int knapsack( int e, int m, int k ) {
	using namespace Tree;
	int u = to[e], fa = to[e^1];
	for( int i = head[u]; ~i; i = nxt[i] )
		if( to[i] != fa )
			for( int j = 1; j <= k; ++j )
				dp(i, m, j);
	g[0] = 1e9;
	for( int i = 1; i <= k; ++i ) g[i] = -1;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( v == fa ) continue;
		for( int j = k-1; j >= 0; --j )
			for( int kk = 1; j+kk <= k; ++kk )
				g[j+kk] = max( g[j+kk], min(g[j], dp(i, m, kk)) );
	}
	// printf( "knapsack: f[%d, %d][%d][%d] = %d\n", fa, u, m, k, g[k] );
	return g[k];
}

int dfs( int u, int fa ) {
	using namespace Tree;
	int sz = x[u];
	for( int i = head[u]; ~i; i = nxt[i] )
		if( to[i] != fa )
			sz += dfs(to[i], u);
	return sz;
}
void solve() {
	using namespace Tree;
	int ans = 1e9;
	memset(f, -1, sizeof f);
	for( int i = head[s]; ~i; i = nxt[i] ) {
		int v = to[i], sz = dfs(v, s);
		if( sz ) ans = min(ans, dp(i, m, sz));
	}
	printf( "%d\n", ans );
}

int main() {
	_w = scanf( "%d", &n );
	Tree::init();
	for(int i=0; i<680; i++)
	{
	    ss[i] = i;
	}
	for( int i = 0; i < n-1; ++i ) {
		int u, v, w;
		_w = scanf( "%d%d%d", &u, &v, &w );
		Tree::adde(u, v, w);
	}
	_w = scanf( "%d%d", &s, &m );
	for( int i = 0; i < m; ++i ) {
		int y;
		_w = scanf( "%d", &y );
		++x[y];
	}
	prelude(), solve();
	return 0;
}