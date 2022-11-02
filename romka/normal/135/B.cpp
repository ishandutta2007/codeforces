#include <iostream>
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
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define sqr(x) (x)*(x)

int x[10], y[10], p[10];

int dist( int i, int j ) {
  return sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
}

bool right(int i, int j, int k) {
  return (y[k]-y[j]) * (y[j]-y[i] ) == (x[k]-x[j]) * (x[i]-x[j]);
}

int main()
{
  forn( i, 8 ) {
    scanf( "%d %d", &x[i], &y[i] );
    p[i] = i;
  }
  do {
    bool ok = true;
    ok &= right( p[0], p[1], p[2] );
    ok &= right( p[1], p[2], p[3] );
    ok &= right( p[2], p[3], p[0] );
    ok &= right( p[3], p[0], p[1] );

    ok &= right( p[4+0], p[4+1], p[4+2] );
    ok &= right( p[4+1], p[4+2], p[4+3] );
    ok &= right( p[4+2], p[4+3], p[4+0] );
    ok &= right( p[4+3], p[4+0], p[4+1] );

    if ( !ok ) continue;

    ok &= dist( p[0], p[1] ) == dist( p[1], p[2] ) && dist( p[1], p[2] ) == dist( p[3], p[2] ) && dist( p[1], p[2] ) == dist( p[0], p[3] );
    ok &= dist( p[5], p[6] ) == dist( p[4], p[7] ) && dist( p[4], p[5] ) == dist( p[6], p[7] );

    if ( ok ) {
      printf( "YES\n" );
      forn( i, 4 ) {
        if ( i ) printf( " " );
        printf( "%d", p[i]+1 );
      }
      printf( "\n" );
      forn( i, 4 ) {
        if ( i ) printf( " " );
        printf( "%d", p[i+4]+1 );
      }

      return 0;
    }

  } while ( next_permutation( p, p+8 ) );

  printf( "NO\n" );
  return 0;
}