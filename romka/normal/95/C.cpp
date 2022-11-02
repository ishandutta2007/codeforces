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
typedef pair<ll,int> pli;

const int maxn = 1010;
const int inf = (int)2e9;
const ll infLL = 1LL << 60;

int n, m, S, T, a, b, c, t[maxn], cost[maxn];
vector<pii> g[maxn];
vector<pii> gn[maxn];
set<pii> ss;
set<pli> ss2;
ll d2[maxn];
int d[maxn];

void go( int S ) {
  ss.clear();

  forn( i, n ) d[i] = inf;
  d[S] = 0;

  ss.insert( pii( 0, S ) );

  while ( !ss.empty() ) {
    pii z = *ss.begin();
    ss.erase( ss.begin() );
    int dst = z.first;
    int v = z.second;
    if ( d[v] < dst ) continue;

    forn( q, g[v].size() ) {
      int nd = dst + g[v][q].second;
      if ( nd <= t[S] )
        if ( d[ g[v][q].first ] > nd ) {
          ss.insert( pii( nd, g[v][q].first ) );
          d[ g[v][q].first ] = nd;
        }
    }
  }

  forn( i, n )
    if ( d[i] < inf )
      gn[S].pb( pii( i, cost[S] ) );

//  forn( i, n ) printf( "%d -> %d = %d (cost %d)\n", S, i, d[i], cost[S] );
}

void go2( int S ) {
  ss2.clear();

  forn( i, n ) d2[i] = infLL;
  d2[S] = 0;

  ss2.insert( pli( 0, S ) );

  while ( !ss2.empty() ) {
    pli z = *ss2.begin();
    ss2.erase( ss2.begin() );
    ll dst = z.first;
    int v = z.second;
    if ( d2[v] < dst ) continue;

    forn( q, gn[v].size() ) {
      ll nd = dst + gn[v][q].second;
        if ( d2[ gn[v][q].first ] > nd ) {
          ss2.insert( pli( nd, gn[v][q].first ) );
          d2[ gn[v][q].first ] = nd;
        }
    }
  }
}

int main() {
  scanf( "%d %d", &n, &m );
  scanf( "%d %d", &S, &T );
  S--, T--;

  forn( i, m ) {
    scanf( "%d %d %d", &a, &b, &c );
    a--, b--;
    g[a].pb( pii( b, c ) );
    g[b].pb( pii( a, c ) );
  }

  forn( i, n )
    scanf( "%d %d", &t[i], &cost[i] );

  forn( i, n )
    go( i );

  go2( S );

  if ( d2[T] == infLL ) printf( "-1\n" );
  else printf( "%I64d\n", d2[T] );

  return 0;
}