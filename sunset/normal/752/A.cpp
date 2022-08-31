#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main()
{
	cin >> n >> m >> k;
	int x = ( k - 1 ) / ( 2 * m ) + 1;
	printf( "%d ", x );
	k -= ( x - 1 ) * 2 * m;
	printf( "%d ", ( k + 1 ) / 2 );
	if( k & 1 ) putchar('L');
	else putchar('R');
}