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

const int inf = 2000010;

int f[110][110][27];
int k;
char buf1[5], buf2[5], s[110];
int g[30][30];

int main()
{
  scanf( "%s %d", s, &k );
  int n = strlen( s );
  forn( i,n ) s[i] -= 'a';
  int z, x;
  scanf( "%d", &z );
  forn( i, z ) {
    scanf( "%s %s %d", buf1, buf2, &x );
    g[ buf1[0]-'a' ][ buf2[0]-'a' ] = x;
  }

  forn( i, n+1 ) forn( j, k+1 ) forn( w, 26 ) f[i][j][w] = -inf;

  forn( i, 26 ) {
    f[0][s[0]!=i][i] = 0; 
  }

  forn( i, n-1 )
    forn( j, k+1 )
      forn( w, 26 )
        if ( f[i][j][w] != -inf )
          forn( t, 26 )
            f[i+1][j+(t!=s[i+1])][t] = max( f[i+1][j+(t!=s[i+1])][t], f[i][j][w] + g[w][t] );

  int ans = -inf;
    forn( j, k+1 )
      forn( w, 26 ) {
        ans = max( ans, f[n-1][j][w] );
//        if ( f[n-1][j][w] != -inf ) printf( "f[%d %d %c] = %d\n", n-1, j, 'a'+w, f[n-1][j][w] );
      }

  printf( "%d\n", ans );
      
  return 0;
}