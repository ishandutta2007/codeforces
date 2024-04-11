#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

#define sqr(x) (x)*(x)

struct object{
  int r, x, y;

  bool contains( object& a )
  {
    ll d = sqr((ll)a.x-x) + sqr((ll)a.y-y);
    return d < (ll)r*r && a.r < r;
  }
};

int n, m, k;
object p[1010], c[1010];
vector<int> g[1010];
int pr[1010], pc[1010];
int rmq[40010][15];
vector<int> val, order;
int pos[1010];
int n2[40010];

void dfs( int i, int h )
{
  order.pb( i );
  val.pb( h );
  forn( j, g[i].size() )
  {
    dfs( g[i][j], h+1 );
    order.pb( i );
    val.pb( h );
  }
}

int getmin( int i, int j )
{
  if ( i > j ) swap( i, j );
  int len = j-i+1;
  int q = n2[len];
  return min( rmq[i][q], rmq[j-(1<<q)+1][q] );
}

int main()
{
  scanf( "%d %d %d", &n, &m, &k );
  forn( i, n ) scanf( "%d %d", &p[i].x, &p[i].y );
  forn( i, m ) scanf( "%d %d %d", &c[i].r, &c[i].x, &c[i].y );

  forn( i, m ) pr[i] = -1;

  forn( i, m )
    forn( j, m ) if ( i != j )
      if ( c[i].contains( c[j] ) )
        if ( pr[j] == -1 || c[ pr[j] ].r > c[i].r ) pr[j] = i;    

  forn( i, m )
  {
//    printf( "%d -> %d\n", pr[i]+1, i+1 );
    g[ pr[i]+1 ].pb( i+1 );
  }

  dfs( 0, 0 );

  forn( i, order.size() )
    pos[ order[i] ] = i;

//  forn( i, order.size() ) printf( "%d ", order[i] ); printf( "\n" );
//  forn( i, val.size() ) printf( "%d ", val[i] ); printf( "\n" );

  forn( i, n ) pc[i] = -1;

  forn( i, n )
    forn( j, m )
      if ( c[j].contains( p[i] ) )
        if ( pc[i] == -1 || c[ pc[i] ].r > c[j].r ) pc[i] = j;

  int N = order.size();

  forn( i, N ) rmq[i][0] = val[i];
  forn( j, 14 )
    forn( i, N-(1<<j) )
      rmq[i][j+1] = min( rmq[i][j], rmq[i+(1<<j)][j] );

  n2[1] = 0;
  for ( int i=2; i<=N; i++ ) n2[i] = ( n2[i>>1] + 1 );

  int a, b;
  forn( i, k )
  {
    scanf( "%d %d", &a, &b );
    a--, b--;
    int x = pc[a]+1;
    int y = pc[b]+1;

    int r = getmin( pos[x], pos[y] );
    printf( "%d\n", val[ pos[x] ] + val[ pos[y] ] - 2*r );
  }
}