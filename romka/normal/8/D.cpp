#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef long double ld;
const ld eps = 1e-10;

int xk, yk, xd, yd, xm, ym, t1, t2;

#define sqr(x) (x)*(x)
#define G(x) printf( "%d\n", x );

 #undef G
 #define G(x) ;

ld dist( ld xa, ld ya, ld xb, ld yb )
{
  return sqrt( sqr(xa-xb) + sqr(ya-yb) );
}

ld d1, d2, dkm, dkd;

bool intersect( ld xk, ld yk, ld rk, ld x2, ld y2, ld r2, ld& xa, ld& ya, ld& xb, ld& yb )
{
  ld d = dist( xk, yk, x2, y2 );
  if ( rk + r2 < d-eps ) return false;
  if ( rk + d < r2-eps ) return false;
  if ( r2 + d < rk-eps ) return false;

  ld x = ( rk*rk - r2*r2 + d*d ) / ( 2*d );
  ld h = rk*rk - x*x;
  if ( fabs( h ) < 1e-7 ) h = 0;
  h = sqrt( h );
  ld ex = ( x2-xk ) / d;
  ld ey = ( y2-yk ) / d;

  ld mx = xk + ex*x;
  ld my = yk + ey*x;
  xa = mx - ey*h;
  ya = my + ex*h;
  xb = mx + ey*h;
  yb = my - ex*h;

  return true;
}

ld rm, rk, rd;

bool ok( ld xx, ld yy )
{
  return dist( xx, yy, xd, yd ) < rd+eps &&
         dist( xx, yy, xm, ym ) < rm+eps &&
         dist( xx, yy, xk, yk ) < rk+eps;
}

bool check( ld X )
{
//  printf( "Checking %.7f\n", (double)X );
  rm = dkm+t1-X;
  rd = d2+t2-X;
  rk = X;

//  printf( "> %.5f %.5f %.5f \n", (double)rm, (double)rd, (double)rk );

  G(0)
  if ( ok( xm, ym ) || ok( xd, yd ) || ok( xk, yk ) ) return true;
  G(1)

  ld xa, ya, xb, yb;
  if ( intersect( xm, ym, rm, xk, yk, rk, xa, ya, xb, yb ) )
  {
    G(11)
//    cout << "### xa = " << xa << ", ya = " << ya << endl;
    if ( ok( xa, ya ) ) return true;
    if ( ok( xb, yb ) ) return true;
  }
  G(2)
  if ( intersect( xd, yd, rd, xk, yk, rk, xa, ya, xb, yb ) )
  {
    if ( ok( xa, ya ) ) return true;
    if ( ok( xb, yb ) ) return true;
  }
  G(3)
  if ( intersect( xm, ym, rm, xd, yd, rd, xa, ya, xb, yb ) )
  {
    if ( ok( xa, ya ) ) return true;
    if ( ok( xb, yb ) ) return true;
  }
  G(4)

  return false;
}

ld solve()
{
  d1 = dist( xk, yk, xm, ym ) + dist( xm, ym, xd, yd );
  d2 = dist( xk, yk, xd, yd );

  if ( d2+t2 > d1-eps ) return min( d1+t1, d2+t2 );

  dkm = dist( xk, yk, xm, ym ); 
  dkd = dist( xk, yk, xd, yd );

  ld ll = 0, rr = 1e5, mm;
  for ( int it=0; it<5000; it++ )
  {
    mm = ( ll+rr ) * 0.5;

    if ( check( mm ) ) ll = mm;
    else rr = mm;
  }

  return ( ll+rr ) * 0.5;
}

int main()
{
  scanf( "%d %d", &t1, &t2 );
  scanf( "%d %d %d %d %d %d", &xk, &yk, &xd, &yd, &xm, &ym );

  printf( "%.10f\n", (double)solve() );
}