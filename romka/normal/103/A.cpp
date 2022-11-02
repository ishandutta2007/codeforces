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
  int n, x;
  scanf( "%d", &n );
  ll ans = 0;
  forn( i, n ) {
    scanf( "%d", &x );
    ans += (ll)(x-1) * (ll)( i+1 ) + 1;
  }
  printf( "%I64d\n", ans );

  return 0;
}