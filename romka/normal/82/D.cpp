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

int f[1010][1010];
pii ans[1010][1010], p[1010][1010];
int n, a[1010];

void restore( int i, int j ) {
  if ( i == 0 && j== 0 ) return;
  if ( i == n && j == n ) printf( "%d\n", f[i][j] );

  restore( p[i][j].first, p[i][j].second );           
  printf( "%d", ans[i][j].first+1 );
  if ( ans[i][j].second != -1 ) printf( " %d", ans[i][j].second+1 );
  printf( "\n" );
}

void setval( int i, int j, int val, int a1, int a2, int p1, int p2 ) {
  int& cur = f[i][j];
  if ( cur == 0 || cur > val ) {
    cur = val;
    ans[i][j] = pii( a1, a2 );
    p[i][j] = pii( p1, p2 );
  }
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );

  if ( n == 1 ) {
    printf( "%d\n", a[0] );
    printf( "1\n" );
    return 0;
  }

  if ( n == 2 ) {
    printf( "%d\n", max( a[0], a[1] ) );
    printf( "1 2\n" );
    return 0;
  }

  f[3][2] = max( a[0], a[1] );
  ans[3][2] = pii( 0, 1 );
  f[3][1] = max( a[0], a[2] );
  ans[3][1] = pii( 0, 2 );
  f[3][0] = max( a[1], a[2] );
  ans[3][0] = pii( 2, 1 );

  for ( int i=3; i<n-1; i++ ) {
    for ( int j=0; j<i; j++ )
      if ( f[i][j] > 0 ) {
        setval( i+2, j, f[i][j] + max( a[i], a[i+1] ), i, i+1, i, j );
        setval( i+2, i, f[i][j] + max( a[j], a[i+1] ), j, i+1, i, j );
        setval( i+2, i+1, f[i][j] + max( a[j], a[i] ), j, i, i, j );
      }
  }

  if ( ~n&1 ) {
    forn( j, n-1 )
      if ( f[n-1][j] > 0 )
        setval( n, n, f[n-1][j] + max( a[j], a[n-1] ), j, n-1, n-1, j );
  }
  else {
    forn( j, n )
      if ( f[n][j] > 0 )
        setval( n, n, f[n][j] + a[j], j, -1, n, j );
  }
/*
  for ( int i=0; i<=n; i++ )
    for ( int j=0; j<i; j++ )
      if ( f[i][j] != 0 )
        printf( "f[%d][%d] = %d\n", i, j, f[i][j] );
*/
  restore( n, n );

  return 0;
}