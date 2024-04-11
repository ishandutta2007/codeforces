#include <cstdio>
#include <string>
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
typedef double ld;
typedef pair<int,int> pii;

struct point {
  ld x, y, z;

  void read() {
    int tx, ty, tz;
    scanf( "%d %d %d", &tx, &ty, &tz );
    x = tx, y = ty, z = tz;
  }

  point() { x=y=z = 0; }
  point( ld a, ld b, ld c ) {
    x = a;
    y = b;
    z = c;
  }

  point mult( ld co ) {
    return point( x*co, y*co, z*co );
  }
};

#define sqr(x) (x)*(x)

ld dist( const point& a, const point& b ) {
  return sqrt( sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z) );
}

point operator+( const point& a, const point& b ) {
  return point( a.x+b.x, a.y+b.y, a.z+b.z );
}

vector<point> g[110];
int n, R, r[110];
point A, v, x, O[110];
ld ans;

ld f( const point& p, ld t ) {
  point z = A + v.mult( t );
  return dist( z, p );
}

ld getmin( const point& p, ld needR ) {
  ld l = 0, r = 1e8, m1, m2, tt;
  forn( it, 400 ) {
    m1 = l + ( r-l ) / 3;
    m2 = r - ( r-l ) / 3;

    if ( f( p, m1 ) < f( p, m2 ) ) r = m2;
    else l = m1;     
  }

  tt = (l+r) * 0.5;
  if ( f( p, tt ) < needR + 1e-8 ) {
    l = 0, r = tt;
    forn( it, 400 ) {
      m1 = ( l+r ) * 0.5;
      if ( f( p, m1 ) > needR ) l = m1;
      else r = m1;
    }

    return (l+r) * 0.5;
  }

  return 1e11;
} 

ld check( int id ) {
  ld res = 1e10;
  ld t = getmin( O[id], R+r[id] );
//  printf( "center: %.5f t=%.5f\n", md, t );

  if ( t < res ) res = t;
  forn( i, g[id].size() ) {
    t = getmin( g[id][i], R );
//    printf( "%.5f t=%.5f\n", md, t );
    if ( t < res ) res = t;
  }

  return res;
}

int main()
{
  int m;
  A.read();
  v.read();
  scanf( "%d", &R );
  scanf( "%d", &n );
  forn( i, n ) {
    O[i].read();
    scanf( "%d", &r[i] );
    scanf( "%d", &m );
    forn( j, m ) {
      x.read();
      g[i].pb( O[i] + x );
    } 
  }

  ans = 1e9;
  forn( i, n )
    ans = min( ans, check( i ) );

  if ( ans > 1e9 - 3 ) printf( "-1\n" );
  else printf( "%.10f\n", (double)ans );

  return 0;
}