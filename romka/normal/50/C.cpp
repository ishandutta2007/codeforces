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

const int sh = (int)1e6 + 3;
const int sz = sh+sh+5;

int n, xx, yy;
int miny, maxy, maxx, minx;
int x[sh], y[sh];

int aa( int x )
{
  return x < 0 ? -x : x;
}

int main()
{
  scanf( "%d", &n );
  maxy = maxx = -1;
  miny = minx = sh+sh+sh;

  forn( i, n )
  {
    scanf( "%d %d", &xx, &yy );
    xx += sh, yy += sh;
    if ( xx-1 < minx ) minx = xx-1;
    if ( xx+1 > maxx ) maxx = xx+1;
    if ( yy-1 < miny ) miny = yy-1;
    if ( yy+1 > maxy ) maxy = yy+1;
    x[i] = xx, y[i] = yy;
  }

  int ans = maxx - minx + maxy - miny;
  ans <<= 1;
  int ul, ur, dl, dr;
  ul=ur=dl=dr = sz;

  forn( i, n )
  {
    ul = min( ul, maxy-y[i]+x[i]-minx-1 );
    ur = min( ur, maxy-y[i]+maxx-x[i]-1 );
    dl = min( dl, y[i]-miny+x[i]-minx-1 );
    dr = min( dr, y[i]-miny+maxx-x[i]-1 );
  }

  ans -= dl+dr+ul+ur;

  printf( "%d\n", ans );

  return 0;
}