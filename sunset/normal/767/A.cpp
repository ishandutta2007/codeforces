#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int n, a[MAXN], pos[MAXN];

int main()
{
	scanf( "%d", &n );
	int cur = n;
	for( int i = 1 ; i <= n ; i++ )
	{
		scanf( "%d", &a[ i ] );
		pos[ a[ i ] ] = i;
		while( pos[ cur ] ) printf( "%d ", cur-- );
		putchar( 10 );
	}
}