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

int n, k, x;
vector<int> g[200*201];
vector<int> gt[210];
int col[210][210];
bool is[210];
bool u[210];
vector<int> cur;

void dfs( int i ) {
  u[i] = true;
  cur.pb( i );
  forn( j, gt[i].size() )
    if ( !u[ gt[i][j] ] ) dfs( gt[i][j] );
}

int main()
{
  scanf( "%d", &n );
  int cnt = n * (n-1) / 2;

  forn( i, cnt ) {
    scanf( "%d", &k );
    forn( j, k ) {
      scanf( "%d", &x );
      g[i].pb( x );
      is[x] = true;
    }
  }

  if ( n == 2 ) {
    printf( "1 %d\n", g[0][0] );
    printf( "%d", (int)g[0].size()-1 );
    for ( int j=1; j<(int)g[0].size(); j++ )
      printf( " %d", g[0][j] );
    printf( "\n" );
    return 0;
  }

  forn( i, cnt )
    forn( j, g[i].size() )
      forn( w, j ) {
        col[ g[i][w] ][ g[i][j] ]++;
        col[ g[i][j] ][ g[i][w] ]++;
      } 

  for ( int i=1; i<=200; i++ )
    for ( int j=1; j<i; j++ )
      if ( col[i][j] == n-1 ) {
        gt[i].pb( j );
        gt[j].pb( i );
      }

  for ( int i=1; i<=200; i++ )
    if ( is[i] && !u[i] ) {
      cur.clear();
      dfs( i );
      printf( "%d", (int)cur.size() );
      forn( j, cur.size() ) printf( " %d", cur[j] );
      printf( "\n" );
    } 

  return 0;
}