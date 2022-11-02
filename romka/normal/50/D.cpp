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

struct point {
  int x, y;
};

int n, k;
double ee;
point p[110];
ld d[110], prob[110];
ld f[110][110];

#define sqr(x) (x)*(x)

ld dist( point& a, point& b )
{
  return sqrt( 1.0*sqr(a.x-b.x) + 1.0*sqr(a.y-b.y) );
}

bool check( ld r )
{
  ld r2 = r*r;
  forn( i, n )
    if ( d[i] < r ) prob[i] = 1;
    else prob[i] = exp( 1 - sqr(d[i]) / r2 );

  f[0][0] = 1 - prob[0];
  f[0][1] = prob[0];

  for ( int i=1; i<n; i++ )
    forn( j, i+2 )
    {
      f[i][j] = f[i-1][j] * ( 1-prob[i] );
      if ( j ) f[i][j] += f[i-1][j-1] * prob[i];
    }

  ld sum = 0;
  for ( int i=k; i<=n; i++ ) sum += f[n-1][i];
  return 1-sum < ee;      
}

int main()
{
  scanf( "%d", &n );
  scanf( "%d %lf", &k, &ee );
  ee /= 1000.0;
  scanf( "%d %d", &p[n].x, &p[n].y );
  forn( i, n ) 
  {
    scanf( "%d %d", &p[i].x, &p[i].y );
    d[i] = dist( p[i], p[n] );
  }

  ld l = 0, r = 4000, m;
  while ( r-l > 1e-7 )
  {
    m = ( l+r ) * 0.5;
    if ( check( m ) ) r = m;
    else l = m;
  } 

  printf( "%.10f\n", (double)( l+r ) * 0.5 );

  return 0;
}