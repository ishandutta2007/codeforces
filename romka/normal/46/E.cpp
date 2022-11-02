#include <cstdio>
#include <iostream>
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

int n, m;
ll f[1600][1600], s[1600][1600];
int a[1600][1600];

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, n ) forn( j, m ) scanf( "%d", &a[i][j] );

  forn( i, n )
  {
    s[i][0] = a[i][0];
    for ( int j=1; j<m; j++ ) s[i][j] = s[i][j-1] + a[i][j];
  }

  forn( j, m ) f[0][j] = s[0][j];

  for ( int i=1; i<n; i++ )
    if ( i&1 )
    {
      ll mj = f[i-1][m-1];
      for ( int j=m-2; j>=0; j-- )
      {
        f[i][j] = s[i][j] + mj;
        mj = max( mj, f[i-1][j] );
      }
    }
    else
    {
      ll mj = f[i-1][0];
      for ( int j=1; j<m; j++ )
      {
        f[i][j] = s[i][j] + mj;
        mj = max( mj, f[i-1][j] );
      }
    }
/*
  forn( i, n )
  {
    forn( j, m ) printf( "%I64d ", f[i][j] );
    printf( "\n" );
  } 
*/
  ll ans = -10000LL * 1600LL * 1600LL;
  for ( int j=1; j<m-1; j++ ) ans = max( ans, f[n-1][j] );

  if ( (n-1)&1 ) ans = max( ans, f[n-1][0] );
  else ans = max( ans, f[n-1][m-1] );

  cout << ans << endl;

  return 0;
}