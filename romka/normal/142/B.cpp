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
  int n, m;
  scanf( "%d %d", &n, &m );
  if ( m < n ) swap( n, m );

  if ( n == 1 ) {
    printf( "%d\n", m );
    return 0;
  }

  if ( n == 2 ) {
    int ans = 4 + (m-n);
    if ( (m-n) % 4 == 1 ) ans--;
    if ( (m-n) % 4 == 2 ) ans -= 2;
    if ( (m-n) % 4 == 3 ) ans--;
    printf( "%d\n", ans );
    return 0;
  }

  int s = 5;
  int d = 3;
  for ( int i=4; i<=n; i++ ) {
    if ( i&1 ) d += 2;
      s += d;
  }

  int q1 = n/2;
  int q2 = n-q1;
  int z = m-n;
  int c2 = z/2;
  int c1 = z-c2;

  printf( "%d\n", s + c1*q1 + c2*q2 );    
 
  return 0;
}