#include <bits/stdc++.h>

using namespace std;

int cur,a,n;

char ch[10];

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d%s", &a, ch );
		if( !cur && ch[ 0 ] != 'S' ) return printf( "NO\n" ), 0;
		if( cur == 20000 && ch[ 0 ] != 'N' ) return printf( "NO\n"), 0;
		if( ch[ 0 ] == 'S' ) cur += a;
		if( ch[ 0 ] == 'N' ) cur -= a;
		if( cur < 0 || cur > 20000 ) return printf( "NO\n" ), 0;
	}
	if( cur ) return printf( "NO\n" ),0;
	else return printf( "YES\n" ), 0;
}