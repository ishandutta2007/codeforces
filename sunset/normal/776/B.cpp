#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int p[MAXN], tot, n;
bool chk[MAXN];

inline int init()
{
	n++;
	for( int i = 2 ; i <= n ; i++ )
	{
		if( !chk[ i ] ) printf( "1 " ), p[ ++tot ] = i;
		else printf( "2 " );
		for( int j = 1 ; i * p[ j ] <= n ; j++ )
		{
			chk[ i * p[ j ] ] = 1;
			if( i % p[ j ] == 0 ) break;
		}
	}
}

int main()
{
	cin >> n;
	if( n <= 2 ) cout << 1 << endl;
	else cout << 2 << endl;
	init();
}