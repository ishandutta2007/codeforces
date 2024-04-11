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

int n, a[110];

int main() {
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );
  sort( a, a+n );
  int cur = 10;
  int cnt = 0;
  int penalty = 0;
  forn( i, n ) {
    if ( cur + a[i] > 720 ) break;
    if ( cur + a[i] > 360 ) penalty += cur + a[i] - 360;
    cur += a[i];
    cnt++;
  }
  printf( "%d %d\n", cnt, penalty );
  return 0;
}