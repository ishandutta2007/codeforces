#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;

long long n, m, topa, topb, a[MAXN], b[MAXN];

int main()
{
	cin >> n >> m;
	long long block = sqrt( n );
	for( long long i = 1 ; i <= block ; i++ )
		if( n % i == 0 )
		{
			a[ ++topa ] = i;
			if( i * i != n ) b[ ++topb ] = n / i;
		}
	if( topa + topb < m ) return printf( "-1\n" ), 0;
	if( m <= topa ) return cout << a[ m ] << endl, 0;
	return cout << b[ topb - ( m - topa ) + 1 ] << endl, 0;
}