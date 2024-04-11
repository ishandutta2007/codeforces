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

const int maxn = 100010;

int a[maxn];
ll f[maxn];
vector<int> g[maxn];
vector<int> id[maxn];
int n, x, y, root;

bool cmp( int i, int j ) {
  return f[i] > f[j];
} 

void dfs( int i, int p ) { 
//  printf( "dfs %d %d\n", i, p );
  forn( j, g[i].size() )
    if ( g[i][j] != p && a[ g[i][j] ] != 0 ) {
      a[ g[i][j] ]--;
      dfs( g[i][j], i );
      id[i].pb( g[i][j] );
    }

  sort( id[i].begin(), id[i].end(), cmp );

  f[i] = 0;
  forn( q, id[i].size() ) {
    int j = id[i][q];
    if ( a[i] > 0 ) {
      f[i] += f[j] + 2;
      a[i]--;
    } else break;
  }

  forn( q, id[i].size() ) {
    int j = id[i][q];
    int x = min( a[i], a[j] );
    a[j] -= x;
    a[i] -= x;
    f[i] += x << 1;
  }

/*      ans++;
      a[ g[i][j] ]--;
      dfs( g[i][j], i );
      a[i]--;
      ans++;
      int x = min( a[i], a[ g[i][j] ] );
      ans += x << 1;
      a[i] -= x;
      a[ g[i][j] ] -= x;
    } */
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );
  forn( i, n-1 ) {
    scanf( "%d %d", &x, &y );
    x--, y--;
    g[x].pb( y );
    g[y].pb( x ); 
  } 
  scanf( "%d", &root );
  root--;

  dfs( root, -1 );

//  forn( i, n ) printf( "%d ", a[i] ); printf( "\n" );

  printf( "%I64d\n", f[root] );
  return 0;
}