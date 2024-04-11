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

int n, m, deg[110];
vector<int> g[110];
int a, b, u[110];

int dfs( int i ) {
  if ( u[i] ) return 0;
  u[i] = true;

  int res = 1;
  forn( j, g[i].size() )
    res += dfs( g[i][j] );

  return res;
}

bool check() {
  int ac = 0;

  forn( i, n )
    if ( deg[i] != 2 && !u[i] ) return false;

  forn( i, n )
    if ( !u[i] ) {
      if ( ac > 0 ) return false;
      ac = dfs( i );
    }

  return ac >= 3;
}

int main() {
  scanf( "%d %d", &n, &m );
  forn( i, m ) {
    scanf( "%d %d", &a, &b );
    a--, b--;
    g[a].pb( b );
    g[b].pb( a );
    deg[a]++;
    deg[b]++;
  }

  bool ok = true;
  while ( ok ) {
    ok = false;
    forn( i, n ) 
      if ( deg[i] == 1 && !u[i] ) {
        u[i] = true;
        forn( j, g[i].size() ) {
          int y = g[i][j];
          if ( !u[y] ) {
            deg[y]--;
          }
        }
        ok = true;
        break;
      }
  }

  if ( check() ) printf( "FHTAGN!\n" );
  else printf( "NO\n" );

  return 0;
}