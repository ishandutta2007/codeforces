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

const int MAXN = 300005;

int cnta[26], cntb[26], cura, curb = 25, n;
char s[MAXN];

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%s", s );
	for( int i = 0 ; s[ i ] ; i++ ) cnta[ s[ i ] - 'a' ]++;
	scanf( "%s", s );
	for( int i = 0 ; s[ i ] ; i++ ) cntb[ s[ i ] - 'a' ]++;
	n = strlen( s );
	while( !cntb[ curb ] ) curb--;
	while( !cnta[ cura ] ) cura++;
	for( int i = 0 ; s[ i ] ; i++ )
	{
		if( cura >= curb )
		{
			if( ( n & 1 ) == ( i & 1 ) )
				for( ; s[ i ] ; i++ )
				{
					if( !( i & 1 ) )
					{
						cntb[ curb ]--; putchar( curb + 'a' );
						while( !cntb[ curb ] ) curb--;
					}
					else
					{
						cnta[ cura ]--; putchar( cura + 'a' );
						while( !cnta[ cura ] ) cura++;
					}
				}
			else
				for( ; s[ i ] ; i++ )
				{
					if( i & 1 )
					{
						cntb[ curb ]--; putchar( curb + 'a' );
						while( !cntb[ curb ] ) curb--;
					}
					else
					{
						cnta[ cura ]--; putchar( cura + 'a' );
						while( !cnta[ cura ] ) cura++;
					}
				}
			break;
		}
		if( i & 1 )
		{
			cntb[ curb ]--; putchar( curb + 'a' );
			while( !cntb[ curb ] ) curb--;
		}
		else
		{
			cnta[ cura ]--; putchar( cura + 'a' );
			while( !cnta[ cura ] ) cura++;
		}
	}
}