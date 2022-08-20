#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200020;

int l, r, ans, n, m, p[MAXN];
char s1[MAXN], s2[MAXN];
bool vis[MAXN];

inline bool chk(int len)
{
	memset( vis, 0, sizeof vis );
	int cur = 1;
	for( int i = 1 ; i <= len ; i++ ) vis[ p[ i ] ] = 1;
	for( int i = 1 ; i <= n ; i++ )
	{
		if( vis[ i ] ) continue;
		if( s1[ i ] == s2[ cur ] )
		{
			cur++;
			if( cur > m ) return true;
		}
	}
	return false;
}

int main()
{
	scanf( "%s%s", s1 + 1, s2 + 1 ); n = strlen( s1 + 1 ); m = strlen( s2 + 1 );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &p[ i ] );
	l = 1, r = n - m;
	while( l <= r )
	{
		int mid = l + r >> 1;
		if( chk( mid ) ) ans = mid, l = mid + 1;
		else r = mid - 1;	
	}
	cout << ans << endl;
}