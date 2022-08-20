#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d;

int main()
{
	puts( "YES" );
	scanf( "%d", &n );
	while( n-- )
	{
		scanf( "%d%d%d%d", &a, &b, &c, &d );
		printf( "%d\n", ( ( a & 1 ) << 1 ) + ( b & 1 ) + 1 );
	}
}