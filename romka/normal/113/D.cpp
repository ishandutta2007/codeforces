#include <cstdio>
#include <sstream>
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
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, m, A, B;
double p[25];
double a[625][625], l[625][625], u[625][625];
vector<int> g[25];
double y[625], x[625], b[625];
int id[25][25];

void edge( int ea, int b, int c, int d, double e ) {
  if ( ea < b ) swap( ea, b );
  if ( c < d ) swap( c, d );
//  if ( id[ea][b] == id[c][d] && ea != b ) e = -e;
  a[ id[ea][b] ][ id[c][d] ] += e;
}

int main()
{
  scanf( "%d %d %d %d", &n, &m, &A ,&B );
  A--, B--;
  if ( A < B ) swap( A, B );
  forn( i, m ) {
    int ue, v;
    scanf( "%d %d", &ue, &v );
    ue--, v--;
    g[ue].pb( v );
    g[v].pb( ue );
  }
  forn( i, n ) scanf( "%lf", &p[i] );

  int N = 0;
  forn( i, n )
    forn( j, i+1 )
      id[i][j] = ++N;

    forn( i, N+1 )
      forn( j, N+1 )
        a[i][j] = 0;

    forn( i, n )
      forn( j, i+1 ) {
        if ( i == j ) {
          edge( i, j, i, j, 1 );
          continue;
        }

        edge( i, j, i, j, p[i] * p[j] );
        forn( q, g[i].size() ) {
          int qi = g[i][q];
          edge( i, j, qi, j, ( 1 - p[i] ) / g[i].size() * p[j] );
          forn( qq, g[j].size() ) {
            int qj = g[j][qq];
            edge( i, j, qi, qj, ( 1 - p[i] ) / g[i].size() *
                                ( 1 - p[j] ) / g[j].size() );
          }
        }

        forn( qq, g[j].size() ) {
          int qj = g[j][qq];
          edge( i, j, i, qj, ( 1 - p[j] ) / g[j].size() * p[i] );
        }
      }

/*    forn( i, n )
      forn( j, n )
        forn( q, n )
          forn( w, n )
            printf( "(%d %d) -> (%d %d) = %.5f\n", i, j, q, w, a[i*n+j][q*n+w] ); */

    forn( i, n )
      forn( j, i )
          a[id[i][j]][id[i][j]] -= 1;

    for ( int j=1; j<=N; j++ ) u[1][j] = a[1][j];
    for ( int j=2; j<=N; j++ ) l[j][1] = a[j][1] / u[1][1];

    for ( int i=2; i<=N; i++ ) {
      for ( int j=i; j<=N; j++ ) {
        u[i][j] = a[i][j];
        for ( int k=1; k<=i-1; k++ )
          u[i][j] -= l[i][k] * u[k][j];
      }
      for ( int j=i+1; j<=N; j++ ) {
        l[j][i] = a[j][i];
        for ( int k=1; k<=i-1; k++ )
          l[j][i] -= l[j][k] * u[k][i];
        l[j][i] /= u[i][i];
      }
    }

   for ( int i=1; i<=N; i++ )
     l[i][i] = 1.0;

  forn( d, n ) {
    forn( i, n )
      forn( j, i+1 )
        if ( i != j ) {
          b[id[i][j]] = 0;
        } else
          b[id[i][j]] = i == d;
          
//        b[id[i][j]] = i != j || ( i == j && i == d );
//    forn( i, N ) printf( "%.3f ", b[i+1] ); printf( "\n" );
    for ( int i=1; i<=N; i++ ) {
      y[i] = b[i];
      for ( int j=1; j<i; j++ )
        y[i] -= l[i][j] * y[j];
    }
    for ( int i=N; i>=1; i-- ) {
      x[i] = y[i];
      for ( int j=i+1; j<=N; j++ )
        x[i] -= u[i][j] * x[j];
      x[i] /= u[i][i];
    }
    if ( d ) printf( " " );
    printf( "%.8f", x[id[A][B]] );  
  }
  printf( "\n" );

  return 0;
}