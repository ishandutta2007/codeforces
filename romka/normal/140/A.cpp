#include <cstdio>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int main() {
  int n, R, r;
  cin >> n >> R >> r;

  if ( n == 1 ) {
    printf( r <= R ? "YES\n" : "NO\n" );
    return 0;
  }

  if ( n == 2 ) {
    printf( 2*r <= R ? "YES\n" : "NO\n" );
    return 0;
  }

  long double a = 2 * r;
  long double RR = a / 2 / sin( M_PI / n );
  RR += r;
  if ( RR < R + 1e-9 ) printf( "YES\n" );
  else printf( "NO\n" );
  return 0;
}