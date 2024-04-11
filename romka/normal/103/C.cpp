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

int main() {
  ll x, n, k;
  int p;
  scanf( "%I64d %I64d %d", &n, &k, &p );
  ll q;
  forn( i, p ) {
    scanf( "%I64d", &x );
    x = n-x;
    if ( n&1 ) {
      if ( x == 0 ) q = 1;
      else
        if ( x&1 ) q = x/2 + 2;
        else q = n/2 + x/2 + 1;
    } else {
      if ( x&1 ) q = n/2 + x/2 + 1;
      else q = x/2 + 1;
    }
    if ( q <= k ) printf( "X" );
    else printf( "." );
  }
  return 0;
}