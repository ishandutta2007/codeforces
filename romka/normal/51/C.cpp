#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <memory.h>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ld eps = 1e-8;

int n, x[200010];

bool check( ld m, bool flag )
{
  ld fx = x[0] + 2*m;
//  if ( flag ) printf( "(fx = %.5f)", fx );
  int i = 0;
  while ( i < n && x[i] < fx + eps ) i++;
  if ( flag ) printf( "%.6f ", x[0] + (double)m );

  if ( i == n )
  {
    if ( flag ) printf( "%.6f %.6f\n", 1.0*x[n-1], 1.0*x[n-1] );
    return true;
  }

  fx = x[i] + 2*m;
//  if ( flag ) printf( "(fx = %.5f)", fx );
  if ( flag ) printf( "%.6f ", x[i] + (double)m );
  while ( i < n && x[i] < fx + eps ) i++; 

  if ( i == n )
  {
    if ( flag ) printf( "%.6f\n", 1.0*x[n-1] );
    return true;
  }

  fx = x[i] + 2*m;
//  if ( flag ) printf( "(fx = %.5f)", fx );
  if ( flag ) printf( "%.6f\n", x[i] + (double)m );
  while ( i < n && x[i] < fx + eps ) i++; 

  return i == n;
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &x[i] );

  sort( x, x+n );

  ld l = 0, r = 1e10, m;
  while ( r-l > 1e-7 )
  {
    m = ( l+r ) * 0.5;            
    if ( check( m, false ) ) r = m;
    else l = m;
  }

  printf( "%.6f\n", (double)r );
  check( r, true );
//  printf( "res = %d", check( r, true ) );
}