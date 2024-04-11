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

const int maxn = 310;

int n, pr, val[maxn], valf[maxn][maxn], x, ans[maxn];

int main() {
  scanf( "%d", &n );
  forn( i, n )
    forn( j, n ) {
      scanf( "%d", &pr );
      valf[i][ pr-1 ] = j;
    }
  forn( i, n ) {
    scanf( "%d", &x );
    val[x-1] = i;
  }
  val[n] = (int)1e9;

  forn( i, n ) {
    int best = n+1;
    int cur = n;
    forn( j, n )
      if ( j != i ) {
        if ( val[j] < val[cur] ) cur = j;
        if ( valf[i][cur] < best ) {
          best = valf[i][cur];
          ans[i] = j;
        }
      }
  }

  forn( i, n ) {
    if ( i ) printf( " " );
    printf( "%d", ans[i]+1 );
  }

  return 0;
}