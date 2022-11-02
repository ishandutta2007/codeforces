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

const int di[] = { -1, -1, 1, 1 };
const int dj[] = { -1, 1, -1, 1 };

int n, m;
bool u[230][230][3][3];

void go( int i, int j, int di, int dj ) {
//  printf( "go %d %d %d %d\n", i, j, di, dj );
  u[i][j][di+1][dj+1] = true;
  if ( i+di < 0 || i+di >= n ) di = -di;
  if ( j+dj < 0 || j+dj >= m ) dj = -dj;
  i += di;
  j += dj;
  if ( !u[i][j][di+1][dj+1] ) go( i, j, di, dj );
}

int solve() {
  int res = 0;
  forn( i, n ) forn( j, m ) forn( q, 3 ) forn( w, 3 ) u[i][j][q][w] = false;
  forn( i, n ) {
    forn( j, m )
      if ( !u[i][j][0][0] && !u[i][j][2][2] && !u[i][j][2][0] && !u[i][j][0][2] ) {
        res++;
//        printf( "new %d %d\n", i, j );
        forn( q, 4 ) go( i, j, di[q], dj[q] );
      }
  }
  return res;
}

int gcd( int a, int b ) {
  return b ? gcd( b, a%b ) : a;
}

int main2()
{
  n=2, m=3;
  printf( "%d\n", solve() );
  n=3, m=2;
  printf( "%d\n", solve() );

  for ( n=2; n<=50; n++ ) {
    for ( m=2; m<=50; m++ ) {
      int z = solve();
//      printf( "%3d", z );
      if ( z != gcd( n-1, m-1 )+1 ) printf( "%dx%d : %d, gcd %d\n", n, m, z, gcd( n-1, m-1 )+1 );
    }
    printf( "\n" );
  }
  return 0;
}

int main() {
  int n, m;
  scanf( "%d %d", &n, &m );
  printf( "%d\n", gcd( n-1, m-1 ) + 1 );
  return 0;
}