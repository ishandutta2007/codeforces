#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL phi(LL n)
{
	LL ret = n;
	for( LL i = 2 ; i * i <= n ; i++ )
	{
		if( n % i == 0 ) ret = ret / i * ( i - 1 );
		while( n % i == 0 ) n /= i;
	}
	if( n ^ 1 ) ret = ret / n * ( n - 1 );
	return ret ;
}

int main()
{
	LL n, k;
	cin >> n >> k;
	while( k > 0 && n != 1 )
		n = phi( n ), k -= 2;
	cout << n % 1000000007 << endl;
}