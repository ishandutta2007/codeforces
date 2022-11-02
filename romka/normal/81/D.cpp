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

int n, m, ans[1010];
pii a[45];

int get( int& id, int val ) {
  int res = a[id].second;
  a[id].first--;
  if ( a[id].first == 0 ) id = val;
  return res;
}

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, m ) scanf( "%d", &a[i].first ), a[i].second = i+1;

  forn( i, m ) if ( a[i].first > n/2 ) a[i].first = n/2;

  sort( a, a+m );

  if ( m == 1 ) {
    if ( n == 1 ) printf( "1\n" );
    else printf( "-1\n" );
    return 0;
  }

  if ( m == 2 ) {
    if ( (n&1) || n > 2 * min( a[0].first, a[1].first ) ) {
      printf( "-1\n" );
      return 0;
    }

    forn( i, n ) {
      if ( i ) printf( " " );
      printf( "%d", (i&1)+1 );
    }
    printf( "\n" );
    return 0;
  }

  reverse( a, a+m );

  int ka = 0;
  forn( i, a[0].first ) {
    ans[ka++] = a[0].second;
  }
  ans[ka] = a[0].second;

    for ( int i=1; i<m; i++ )
      forn( j, a[i].first ) {
        bool coll = false;
        forn( q, ka )
          if ( ans[q] == ans[q+1] ) {
            coll = true;
            for ( int z=ka+1; z>q+1; z-- ) ans[z] = ans[z-1];
            ans[q+1] = a[i].second;
            ka++;
            break;
          }

        if ( !coll ) {
          forn( q, ka )
            if ( ans[q] != a[i].second && ans[q+1] != a[i].second ) {
              for ( int z=ka+1; z>q+1; z-- ) ans[z] = ans[z-1];
              ans[q+1] = a[i].second;
              ka++;
              break;
            }
        }

        if ( ka == n ) goto check;
/*
        forn( i, ka+1 ) {
          if ( i ) printf( " " );
          printf( "%d", ans[i] );
        }
        printf( "\n" );
*/
     }

  check: bool ok = ka == n;
  forn( i, n ) {
    if ( ans[i] == ans[i+1] ) ok = false;
    if ( ans[i] < 1 || ans[i] > m ) ok = false;
  }

//  ok = true;

  if ( !ok ) printf( "-1\n" );
  else
    forn( i, n ) {
      if ( i ) printf( " " );
      printf( "%d", ans[i] );
    }

  return 0;
}