#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <memory.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = (int)1e7 + 10;

set<int> ss;
int p[maxn];
bool is[maxn];
int n, a[1000010], aa, bb, cc;

int findset( int x )
{
  return x == p[x] ? x : p[x] = findset( p[x] );
}

void edge( int x, int y )
{
  if ( x < 0 || x > maxn-5 ) return;
  if ( y < 0 || y > maxn-5 ) return;
  if ( is[x] == 0 || is[y] == 0 ) return;
  x = findset( x );
  y = findset( y );
  if ( x&1 ) p[x] = y;
  else p[y] = x;
}

int gcd( int a, int b )
{
  return b ? gcd( b, a%b ) : a;
}

int main()
{
  int N;
  scanf( "%d", &N );
  forn( i, N )
  {
    scanf( "%d", &a[i] );
    is[ a[i] ] = 1;
  }

  forn( i, maxn-5 ) p[i] = i;

  for ( int n=1; n<=3500; n++ )
    for ( int m=n+1; m<=3500; m++ )
      if ( (n&1) == 0 || (m&1) == 0 )
        if ( gcd( n, m ) == 1 )
        {
          aa = m*m - n*n;
          bb = 2*m*n;
          cc = m*m + n*n;

//          printf( "%d %d %d\n", aa, bb, cc );

          edge( aa, bb );
          edge( aa, cc );
          edge( bb, cc );
        }

  forn( i, N ) ss.insert( findset( a[i] ) );
  printf( "%d\n", ss.size() );

  fprintf( stderr, "%.3f sec\n", double(clock()) / CLOCKS_PER_SEC );

  return 0;
}