#include <bits/stdc++.h>
using namespace std;

int a[12], n;

int main()
{
	for(long long i=0,j;i<100000000;i++)j=rand();
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) cin >> a[ i ];
	sort( a, a + n );
	for( int i = 0 ; i < n ; i++ ) printf( "%d ", a[ i ] );
}