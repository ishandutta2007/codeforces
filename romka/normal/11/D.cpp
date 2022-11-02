#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

ll f[19][1<<19];
int u[19][1<<19];

int n, m, a, b, cur, tc;
vector<int> g[20];
int ue[20][20];

ll getf( int i, int mask )
{
  if ( i == cur ) return 1;
  if ( u[i][mask] == tc )
    return f[i][mask];

  ll& res = f[i][mask];
  res = 0;
  u[i][mask] = tc;

  forn( j, g[i].size() )
    if ( ~mask&(1<<g[i][j]) )
      res += getf( g[i][j], mask | ( 1<<i ) );

  return res;
} 

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, m )
  {
    scanf( "%d %d", &a, &b );
    a--, b--;
    g[a].pb( b );
    g[b].pb( a );
  } 

  ll ans = 0;
  int umask = 0;
  for ( cur=0; cur<n; cur++ )
  {
    tc++;
    ll ca = 0;
    forn( j, g[cur].size() )
      if ( g[cur][j] > cur )
    {
      ll z = getf( g[cur][j], umask );
//      cout << g[cur][j] << "->" << cur << ": " << z << endl;
      ca += z - 1;
    }
    ans += ca >> 1;
    umask = ( umask << 1 ) + 1;
  } 

  cout << ans << endl;
}