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

int n;
pii a[5010];
vector<int> g[5010], w[5010];
int p[5010];
int pc[5010], maxpc[5010], where[5010];
int ans[5010];

void dfs( int i, int pr ) {
//  printf( "dfs %d %d\n", i, pr );
  forn( j, g[i].size() )
    if ( g[i][j] != pr ) {
      p[ g[i][j] ] = i;
      dfs( g[i][j], i );
      maxpc[ g[i][j] ] = pc[ g[i][j] ] = w[i][j];
    }
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i].first ), a[i].second = i;

  forn( i, n-1 ) {
    int a, b, c;
    scanf( "%d %d %d", &a, &b, &c );
    a--, b--;
    g[a].pb( b );
    w[a].pb( c );
    g[b].pb( a );
    w[b].pb( c );
  }
/*
  forn( i, n ) {
    printf( "%d: ", i );
    forn( j, g[i].size() ) printf( " %d", g[i][j] );
    printf( "\n" );
  }
*/
  dfs( 0, -1 );
  p[0] = -1;

  sort( a, a+n );

  forn( i, n ) ans[i] = -1, where[i] = i;
  int ready = 0;

  for ( int day=0; ready < n; day++ ) {

    forn( i, n ) pc[i] = maxpc[i];

    forn( i, n ) {
      int q = a[i].second;
      if ( where[q] == 0 ) {
        if ( ans[q] == -1 ) {
          ans[q] = day;
          ready++;
        }
        continue;
      }

      int x = where[q];
      if ( pc[x] > 0 ) {
        where[q] = p[ where[q] ];
        pc[x]--;
      }
    }
  }

  forn( i, n ) {
    if ( i ) printf( " " );
    printf( "%d", ans[i] );
  }
  
  return 0;
}