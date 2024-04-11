#include <cstdio>
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

const int maxn = 1000010;

int n, m, k, kd, d[maxn], a, b;
vector<int> g[maxn];
bool u[maxn];
multiset<int> ss;

int dfs( int i ) {
  int res = 1;
  u[i] = true;

  forn( j, g[i].size() )
    if ( !u[ g[i][j] ] )
      res += dfs( g[i][j] );

  return res;
}

int main()
{
  scanf( "%d %d %d", &n, &m, &k );
  forn( i, m ) {
    scanf( "%d %d", &a, &b );
    a--, b--;
    g[a].pb( b );
    g[b].pb( a );
  }

  kd = 0;
  forn( i, n ) 
    if ( !u[i] ) {
      d[kd++] = dfs( i );
    }

  sort( d, d+kd );
  reverse( d, d+kd );
  
  int total = 0;
  forn( i, kd ) {
    if ( d[i] > k ) d[i] = k;
    total += d[i];
    ss.insert( d[i] );
  }

  for ( int i=0; ; i++ ) {
    if ( total >= 2 * ( (int)ss.size()-1 ) ) {
      printf( "%d\n", i );
      break;
    }

    int a = *ss.begin();
    ss.erase( ss.begin() );
    int b = *ss.begin();
    ss.erase( ss.begin() );
    total = total - a - b + min( a+b, k );
    ss.insert( min( a+b, k ) );
  }

  return 0;
}