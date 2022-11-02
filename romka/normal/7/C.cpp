#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int a, b, c;

ll gcd (ll a, ll b, ll& x, ll& y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
  scanf( "%d %d %d", &a, &b, &c );
  ll x, y, d;
  d = gcd( a, b, x, y );
  if ( c%d != 0 ) printf( "-1\n" );
  else cout << -x*c/d << " " << -y*c/d << endl;
}