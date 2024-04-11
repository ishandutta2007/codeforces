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

int n, a, b, x[100010], mark[100010];
pii ev[100010];

int main()
{
  scanf( "%d", &n );
  scanf( "%d %d", &a, &b );
  forn( i, n ) scanf( "%d", &x[i] );
  
  if ( a == b ) {
    forn( i, a ) printf( "1 ");
    forn( i, b ) {
      if ( i ) printf( " " );
      printf( "2" );
    }
    printf( "\n" );
    return 0;
  } else
  if ( a < b ) {
    forn( i, n ) ev[i] = pii( x[i], -i );
    sort( ev, ev+n );
    forn( i, b ) mark[ -ev[i].second ] = 1;
  } else {
    forn( i, n ) ev[i] = pii( x[i], i );
    sort( ev, ev+n );
    forn( i, b ) mark[ ev[n-i-1].second ] = 1;    
  }
  forn( i, n ) {
    if ( i ) printf( " " );
    printf( "%d", mark[i]+1 );
  }
  return 0;
}