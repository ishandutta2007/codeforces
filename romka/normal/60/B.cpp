#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <memory.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

const int dx[] = { -1, 1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, -1, 1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, 1 };

int k, n, m, x, y, z, nz, nx, ny, qf, qb;
int q[1010][3];
bool u[12][12][12];
bool mm[12][12][12];
char s[15];

void inq( int a, int b, int c )
{
  if ( u[a][b][c] ) return;
  if ( mm[a][b][c] ) return;
  u[a][b][c] = 1;
  q[qf][0] = a;
  q[qf][1] = b;
  q[qf][2] = c;
  qf++;
}

int main()
{
  scanf( "%d %d %d", &k, &n, &m );
  forn( i, k )
    forn( j, n )
    {
      scanf( "%s", s );
      forn( w, m )
        mm[i][j][w] = s[w] == '#';
    }

  scanf( "%d %d", &x, &y );
  x--, y--;

  qb = qf = 0;
  inq( 0, x, y );

  while ( qb < qf )
  {
    z = q[qb][0];
    x = q[qb][1];
    y = q[qb][2];
    qb++;

    forn( qw, 6 )
    {
      nz = z + dz[qw];
      nx = x + dx[qw];
      ny = y + dy[qw];

      if ( nz >= 0 && nz < k && nx >= 0 && nx < n && ny >= 0 && ny < m )
        inq( nz, nx, ny );
    }
  }

  printf( "%d\n", qb );

  return 0;
}