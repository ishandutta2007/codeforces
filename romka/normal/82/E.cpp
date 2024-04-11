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
typedef long double ld;
typedef pair<int,int> pii;

const ld eps = 1e-9;

struct point {
  ld x, y;

  point() { x=y = 0; }
  point( ld a, ld b ) {
    x=a, y=b;
  }
};

bool operator<( const point& a, const point& b ) {
  return a.x < b.x || ( fabs( a.x-b.x ) < eps && a.y < b.y );
}

typedef vector<point> TPoly;

TPoly poly1, poly2, pp;
int left[510], right[510], n, h, f;
pair<ld,int> an[510];

ld area( TPoly& v ) {
  ld res = 0;
  forn( i, (int)v.size()-1 )
    res += ( v[i].y + v[i+1].y ) * ( v[i+1].x - v[i].x );
  if ( res < 0 ) res = -res;
  return res;
}

point intersect( ld xa, ld ya, ld xb, ld yb, ld xc, ld yc, ld xd, ld yd ) {
  ld A1 = yb-ya,
     B1 = xa-xb,
     C1 = -xa*A1 - ya*B1,
     A2 = yd-yc,
     B2 = xc-xd,
     C2 = -xc*A2 - yc*B2;
  ld D = A1*B2 - A2*B1;

  if ( fabs( D ) < 1e-9 ) printf( "%d\n", 1 / 0 );

  ld x = ( C2*B1 - C1*B2 ) / D;
  ld y = ( A2*C1 - A1*C2 ) / D;

  return point( x, y );
}

bool intersectseg( ld xa, ld ya, ld xb, ld yb, ld xc, ld yc, ld xd, ld yd, point& pc ) {
  ld A1 = yb-ya,
     B1 = xa-xb,
     C1 = -xa*A1 - ya*B1,
     A2 = yd-yc,
     B2 = xc-xd,
     C2 = -xc*A2 - yc*B2;
  ld D = A1*B2 - A2*B1;

  if ( fabs( D ) < eps ) return false;

  ld x = ( C2*B1 - C1*B2 ) / D;
  ld y = ( A2*C1 - A1*C2 ) / D;
                                                               
  if ( xa > xb ) swap( xa, xb );
  if ( ya > yb ) swap( ya, yb );
  if ( xc > xd ) swap( xc, xd );
  if ( yc > yd ) swap( yc, yd );

  if ( (x < xa - eps || x > xb + eps) || (x < xc - eps || x > xd + eps) ) return false;
  if ( (y < ya - eps || y > yb + eps) || (y < yc - eps || y > yd + eps) ) return false;

  pc = point( x, y );
  return true;
}

TPoly convexhull( TPoly v ) {
  TPoly vv, res;
  sort( v.begin(), v.end() );

  forn( i, v.size() )
    if ( i && fabs( v[i].x - v[i-1].x ) < eps && fabs( v[i].y - v[i-1].y ) < eps ) continue;
    else vv.pb( v[i] );

  if ( vv.size() < 3 ) return vv;

  ld mx = -1, my = -1;
  int id = -1;
  forn( i, vv.size() )
    if ( id == -1 || vv[i].y < my || ( fabs( vv[i].y - my ) < eps && vv[i].x < mx ) ) {
      id = i;
      my = vv[i].y;
      mx = vv[i].x;
    }

  swap( vv[id], vv[0] );

  for ( int i=1; i<(int)vv.size(); i++ )
    an[i] = make_pair( atan2( vv[i].y - my, vv[i].x - mx ), i );

  sort( an+1, an+(int)vv.size() );

  res.pb( vv[0] );
  for ( int i=1; i<(int)vv.size(); i++ )
    res.pb( vv[ an[i].second ] );

  return res;
}

void printpoly( char* name, TPoly& poly ) {
  printf( "%s: ", name );
  forn( i, poly.size() )
    printf( " (%.3f,%.3f)", poly[i].x, poly[i].y );
  printf( "\n" );
}

int main()
{
  scanf( "%d %d %d", &n, &h, &f );
  forn( i, n ) scanf( "%d %d", &left[i], &right[i] );

  ld ans = 0;

  forn( i, n )
    forn( j, n ) {
      poly1.clear();
      poly2.clear();
      poly1.pb( intersect( 0, f, left[i], h, -10000, h, 10000, h ) );
      poly1.pb( intersect( 0, f, left[i], h, -10000, 0, 10000, 0 ) );
      poly1.pb( intersect( 0, f, right[i], h, -10000, 0, 10000, 0 ) );
      poly1.pb( intersect( 0, f, right[i], h, -10000, h, 10000, h ) );
      poly1.pb( poly1[0] );

      poly2.pb( intersect( 0, -f, left[j], -h, -10000, h, 10000, h ) );
      poly2.pb( intersect( 0, -f, left[j], -h, -10000, 0, 10000, 0 ) );
      poly2.pb( intersect( 0, -f, right[j], -h, -10000, 0, 10000, 0 ) );
      poly2.pb( intersect( 0, -f, right[j], -h, -10000, h, 10000, h ) );
      poly2.pb( poly2[0] );

      if ( j == 0 )
        ans += area( poly1 );
      if ( i == 0 )
        ans += area( poly2 );

//      printpoly( "poly1", poly1 );
//      printpoly( "poly2", poly2 );

      pp.clear();

      point resp( 0, 0 );
      forn( qi, 4 )
        forn( qj, 4 )
          if ( intersectseg( poly1[qi].x, poly1[qi].y, poly1[qi+1].x, poly1[qi+1].y, 
                             poly2[qj].x, poly2[qj].y, poly2[qj+1].x, poly2[qj+1].y, resp ) )
            pp.pb( resp );

      pp = convexhull( pp );
      pp.pb( pp[0] );

//      printpoly( "pp", pp );

      ans -= area( pp );

//      printf( "ans += %.5f + %.5f - %.5f\n", area( poly1 ), area( poly2 ), area( pp ) );
    }

  printf( "%.7f\n", (double)ans );
      

  return 0;
}