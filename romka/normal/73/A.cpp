#include <cstdio>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main()
{
  int x, y, z, k;
  scanf( "%d %d %d %d", &x, &y, &z, &k );
  if ( y > z ) swap( y, z );
  ll ans = 1;
  int lim = min( x-1, k );
  for ( ll a = 0; a <= lim; a++ ) {
    ll b = y-1;
    ll c = z-1;
    if ( a+b+c <= k ) ans = max( ans, (a+1)*(b+1)*(c+1) );
    else {
      b = ( k-a ) / 2;
      c = k-a - b;

//      printf( "> %I64d %I64d %I64d\n", a, b, c );

      if ( a+b+c > k || b > y-1 || c > z-1 ) {
        if ( b > y-1 ) {
          c += b - (y-1);
          b = y-1;
        } else {
          b += c - (z-1);
          c = z-1;
        }
      }

//      printf( "-> %I64d %I64d %I64d\n", a, b, c );

      ans = max( ans, (a+1)*(b+1)*(c+1) );
    }
  } 

  printf( "%I64d\n", ans );

  return 0;
}