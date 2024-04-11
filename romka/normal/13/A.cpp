#include <cstdio>
using namespace std;

int gcd( int a, int b )
{
  return b ? gcd( b, a%b ) : a;
}

int solve( int n, int b )
{
  int res = 0;
  for ( ; n; n/=b ) res += n%b;
  return res;
}

int n;

int main()
{
  scanf( "%d", &n );
  int ans = 0;
  for ( int b=2; b<n; b++ )
    ans += solve( n, b );
  int r = n-2;
  int d = gcd( r, ans );
  printf( "%d/%d\n", ans/d, r/d );
}