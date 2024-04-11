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

const int CO = (int)( sqrt(300000.0) + 0.5 );
const int maxn = 300010;

int n, w[maxn], a, b, q, ind;
pair<pii,int> ev[maxn];
ll sum[maxn], ans[maxn];

void recalc( int b ) {
  for ( int i=n-1; i>=0; i-- ) {
    sum[i] = w[i];
    if ( i+b < n )
      sum[i] += sum[i+b];
  }    
}

int main() {
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &w[i] );
  scanf( "%d", &q );
  forn( i, q ) {
    scanf( "%d %d", &a, &b );
    ev[i].second = i;
    a--;
    ev[i].first = pii( b, a );
  }

  sort( ev, ev+q );

  int lb = -1;
  forn( i, q ) {
    b = ev[i].first.first;
    a = ev[i].first.second;
    ind = ev[i].second;
    if ( b < CO ) {
      if ( b != lb ) recalc( b );
      lb = b;
      ans[ind] = sum[a];
    } else {
      ll res = 0;
      for ( ; a < n; a += b )
        res += w[a];
      ans[ind] = res;
    }
  }

  forn( i, q )
    printf( "%I64d\n", ans[i] );

  return 0;
}