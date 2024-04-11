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

const int maxn = 40010;

vector<int> g[maxn];
int n, m, k, t, a, b;

int main()
{
  scanf( "%d %d %d %d", &n, &m, &k, &t );
  forn( i, k ) {
    scanf( "%d %d", &a, &b );
    a--, b--;
    g[a].pb( b );
  }
  forn( i, n ) sort( g[i].begin(), g[i].end() );

  forn( qqi, t ) {
    scanf( "%d %d", &a, &b );
    a--, b--;
    int cur = 0;
    forn( i, a ) cur += m - (int)g[i].size();
    cur += b;
    bool ok = true;
    forn( j, g[a].size() )
      if ( g[a][j] == b ) {
        ok = false;
        break;
      } else
      if ( g[a][j] < b ) cur--;

    if ( ok ) {
      cur %= 3;
      if ( cur == 0 ) printf( "Carrots\n" );
      if ( cur == 1 ) printf( "Kiwis\n" );
      if ( cur == 2 ) printf( "Grapes\n" );
    } else printf( "Waste\n" );
  }

  return 0;
}