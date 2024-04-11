#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <ctime>
#include <memory.h>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

char s[100010];
int n;
char ans[100010];

void printodd( int n ) {
    forn( i, n ) printf( "4" );
    forn( i, n ) printf( "7" );
}

bool go( int i, int c4, int c7, bool flag ) {
  if ( i == n ) {
    forn( q, n ) printf( "%c", ans[q] );
    return true;
  } else {
    if ( flag ) {
      if ( c4 > 0 ) { ans[i] = '4'; return go( i+1, c4-1, c7, true ); }
      { ans[i] = '7'; return go( i+1, c4, c7-1, true ); }
    } else {
      if ( '4' >= s[i] && c4 > 0 ) {
        ans[i] = '4';
        if ( go( i+1, c4-1, c7, '4' > s[i] ) ) { ans[i] = '4'; return true; }
      }
      if ( '7' >= s[i] && c7 > 0 ) {
        ans[i] = '7';       
        if ( go( i+1, c4, c7-1, '7' > s[i] ) ) { ans[i] = '7'; return true; }
      }
      return false;
    }
  }
}

int main() {
  gets( s );
  n = strlen( s );
  if ( n&1 ) {
    n++;
    printodd( n/2 );
    return 0;
  } else {
    int c4 = n/2, c7 = n/2;
    if ( !go( 0, c4, c7, false ) ) {
      n += 2;
      printodd( n/2 );
    }
  }
  return 0;
}