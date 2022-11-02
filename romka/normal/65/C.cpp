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

const ld eps = 1e-12;

struct point {
  int x, y, z;

  point() { x=y=z = 0; }
  point( int a, int b, int c ) { x=a, y=b, z=c; }

  void read()
  {
    scanf( "%d %d %d", &x, &y, &z );
  }
};

point p[10010], st;
int n;
double vp, vs;

#define sqr(x) (x)*(x)

ld dist( point a, point b )
{
  return sqrt( ld( sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z) ) );
}

ld dist( ld ax, ld ay, ld az, point b )
{
  return sqrt( ld( sqr(ax-b.x) + sqr(ay-b.y) + sqr(az-b.z) ) );
}

int main()
{
  scanf( "%d", &n );
  forn( i, n+1 ) p[i].read();
  scanf( "%lf %lf", &vp, &vs );
  st.read();

  if ( p[0].x == st.x && p[0].y == st.y && p[0].z == st.z )
  {
    printf( "YES\n" );
    printf( "0\n" );
    printf( "%d %d %d\n", st.x, st.y, st.z );
    return 0;
  }

  ld cd = 0, cx, cy, cz;
  for ( int i=1; i<=n; i++ )
  {
    cd += dist( p[i], p[i-1] );
    if ( cd / vs > dist( p[i], st ) / vp - eps )
    {
      cd -= dist( p[i], p[i-1] );
      point vd( p[i].x-p[i-1].x, p[i].y-p[i-1].y, p[i].z-p[i-1].z );
      ld len = dist( point( 0,0,0 ), vd );
      ld l = 0, r = 1, m;
      forn( it, 500 )
      {
        m = ( l+r ) * 0.5;
        cx = p[i-1].x + m * vd.x;
        cy = p[i-1].y + m * vd.y;
        cz = p[i-1].z + m * vd.z;

        if ( dist( cx, cy, cz, st ) / vp - eps < ( cd + m * len ) / vs ) r = m;
        else l = m;
      }

      printf( "YES\n" );
      printf( "%.10f\n", (double)( (cd+r*len) / vs ) );
      printf( "%.10f %.10f %.10f\n", double(cx), double(cy), double(cz) );

      return 0;
    }
  }

  printf( "NO\n" );  

  return 0;
}