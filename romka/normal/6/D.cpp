#include <cstdio>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
const int inf = (int)1e9;

int n, a, b, h[20];

int f[20][20][20], p[20][20][20], pj[20][20][20], pk[20][20][20];

int dec( int a, int b )
{
  int res = a-b;
  if ( res < 0 ) res = 0;
  return res;
}

int main()
{
  scanf( "%d %d %d", &n, &b, &a );
  forn( i,n ) 
  {
    scanf( "%d", &h[i] );
    h[i]++;
  }

  forn( i, 11 )
    forn( j, 17 )
      forn( k, 17 )
        f[i][j][k] = inf;

  f[1][ h[0] ][ h[1] ] = 0;

  for ( int i=1; i<n-1; i++ )
    forn( j, 17 )
      forn( k, 17 )
        if ( f[i][j][k] != inf )
        {
          forn( q, 17 )
          {
            int jn = dec( j, a*q );
            int kn = dec( k, b*q );
            int ln = dec( h[i+1], a*q );
            if ( jn == 0 )
              if ( f[i+1][kn][ln] > f[i][j][k] + q )
              {
                f[i+1][kn][ln] = f[i][j][k] + q;
                p[i+1][kn][ln] = q;
                pj[i+1][kn][ln] = j;
                pk[i+1][kn][ln] = k;
              }
          }
        }

  int jn = 0, kn = 0;
  printf( "%d\n", f[n-1][0][0] );
  for ( int i=n-1; i>1; i-- )
  {
    forn( q, p[i][jn][kn] ) printf( "%d ", i );
    int jb = jn;
    jn = pj[i][jn][kn];
    kn = pk[i][jb][kn];
  }
}