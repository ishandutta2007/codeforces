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

const int md = 1000000007;

int g[260][2], f[260];
bool okhor[260][260], okver[260][260];
int n, m;
char a[2010][2010];

bool okcol( int j ) {
  if ( n&1 ) return false;

  forn( i, n ) if ( !okver[i][j] ) return false;

  return true;
}

int get2c( int j ) {
  g[0][0] = 1;
  g[0][1] = 0;
  g[1][1] = okhor[0][j] && okhor[0][j+1];
  g[1][0] = 0;
  for ( int i=2; i<=n; i++ ) {
    g[i][0] = g[i][1] = 0;
    if ( okhor[i-1][j] && okhor[i-1][j+1] ) g[i][1] = g[i-1][0] + g[i-1][1];
    if ( okver[i-1][j] && okver[i-2][j] && okver[i-1][j+1] && okver[i-2][j+1] ) {
      g[i][0] += g[i-2][0];
      g[i][1] += g[i-2][1];
    }
    if ( g[i][0] >= md ) g[i][0] -= md;
    if ( g[i][1] >= md ) g[i][1] -= md;
  }
  return g[n][1];  
}

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, 4*n+1 )
    scanf( "%s", a[i] );

  forn( i, n )
    forn( j, m ) {
      string cur = "";
      int si = i * 4 + 1;
      int sj = j * 4 + 1;
      forn( di, 3 ) 
        forn( dj, 3 )
          cur += a[si+di][sj+dj];

      okver[i][j+1] = ( cur == "....O...." || 
                      cur == "..O...O.." ||
                      cur == "..O.O.O.." ||
                      cur == "O.O...O.O" ||
                      cur == "O.O.O.O.O" ||
                      cur == "........." || 
                      cur == "O.OO.OO.O" );

      okhor[i][j+1] = ( cur == "....O...." || 
                      cur == "O.......O" ||
                      cur == "O...O...O" ||
                      cur == "O.O...O.O" ||
                      cur == "O.O.O.O.O" ||
                      cur == "........." ||
                      cur == "OOO...OOO" );

    }

  f[0] = 1;
  f[1] = okcol( 1 );

  for ( int j=2; j<=m; j++ ) {
    f[j] = 0;
    if ( okcol( j ) ) f[j] = f[j-1];
    f[j] += ( (ll)(f[j-2]) * get2c( j-1 ) ) % md;
    if ( f[j] >= md ) f[j] -= md;
  }

  printf( "%d\n", f[m] );

  return 0;
}