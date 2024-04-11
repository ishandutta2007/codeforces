#include <cstdio>
#include <vector>
#include <string>
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

const int maxn = 1010;

int n, m, k, x, y;
vector<pii> g[maxn];
map<string,int> mm;
int key1[maxn], key2[maxn], comp1[maxn], comp2[maxn], start1[maxn], start2[maxn];
int kid;
bool unlocked[maxn];
bool u[maxn][maxn], u2[maxn];
int q[maxn*maxn*2][2], qb, qf;
int v1[maxn], v2[maxn];
int start[maxn];

int getid( string s )
{
  if ( mm.find( s ) == mm.end() ) mm[s] = kid++;
  return mm[s];
}

char s[1230];

void clear()
{
  memset( u, 0, sizeof(u) );
  memset( u2, 0, sizeof(u2) );
  memset( unlocked, 0, sizeof(unlocked) );
  qb = qf = 0;
}

void inq( int x, int y )
{
  if ( u[x][y] ) return;
  u[x][y] = 1;
  q[qf][0] = x;
  q[qf][1] = y;
  qf++;
}

void unlock( int i )
{
// printf( "unlock %d\n", i );
  unlocked[i] = true;
  forn( w, m )
  {
    if ( u[w][ v1[i] ] )
      inq( w, v2[i] );
    if ( u[w][ v2[i] ] )
      inq( w, v1[i] );
  }
}

void dfs( int i, int* comp, int cc )
{
  u2[i] = true;
  comp[i] = cc;

  forn( j, g[i].size() )
    if ( unlocked[ g[i][j].second ] && !u2[ g[i][j].first ] )
      dfs( g[i][j].first, comp, cc );
}

void solve( int* comp, int* key, int* start )
{
//  printf( "SOLVE\n" );
  int xx, z;
  forn( i, k )
  {
    scanf( "%s", s );
    int id = getid( string( s ) );
    scanf( "%d", &xx );
    start[id] = xx-1;
    scanf( "%d", &z );
    forn( q, z )
    {
      scanf( "%d", &xx );
      xx--;
      key[xx] = start[id];
      inq( xx, start[id] );
    }
  }

  while ( qb < qf )
  {
    int cx = q[qb][0];
    int cy = q[qb][1];
//    printf( "%d %d\n", cx, cy );
    qb++;

    forn( j, g[cy].size() )
    {
//      printf( "edge %d -> %d (%d)\n", cy, g[cy][j].first, g[cy][j].second );
      int to = g[cy][j].first;
      if ( unlocked[ g[cy][j].second ] ) inq( cx, to );
      else 
        if ( g[cy][j].second == cx )
          unlock( cx );
    }

  }

  int cc = 1;
  forn( i, n )
    if ( !u2[i] )
    {
      dfs( i, comp, cc );
      cc++;      
    }

//  forn( i,n ) printf( "%d ", comp[i] ); printf( "\n" );
}

int main()
{
//  freopen( "input.txt", "r", stdin );

  scanf( "%d %d %d", &n, &m, &k );
  forn( i, m )
  {
    scanf( "%d %d", &x, &y );
    x--, y--;
    v1[i] = x, v2[i] = y;
    g[x].pb( pii( y, i ) );
    g[y].pb( pii( x, i ) );
  }

  solve( comp2, key2, start2 );
  clear();
  solve( comp1, key1, start1 );

    forn( i, n )
      if ( start1[i] != start2[i]  )
        if ( comp1[ start1[i] ] != comp1[ start2[i] ] || comp2[ start1[i] ] != comp2[ start2[i] ] )
        {
          printf( "NO\n" );
          return 0;
        }

    forn( i, m )
      if ( key1[i] != key2[i]  )
        if ( comp1[ key1[i] ] != comp1[ key2[i] ] || comp2[ key1[i] ] != comp2[ key2[i] ] )
        {
          printf( "NO\n" );
          return 0;
        }

  printf( "YES\n" );
  return 0;
}