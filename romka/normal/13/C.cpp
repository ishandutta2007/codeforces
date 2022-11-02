#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
typedef long long ll;
const ll infLL = 1LL << 60;

int n, a[5010];
int b[5010], nb;
ll f[2][5010];

int main()
{
  scanf( "%d", &n );
  forn( i,n )
    scanf( "%d", &a[i] );

  forn( i,n ) b[i] = a[i];
  sort( b, b+n );
  nb = unique( b, b+n ) - b;

  forn( i,nb ) f[0][i] = abs( a[0] - b[i] );

  for ( int i=1; i<n; i++ )
  {
    int fl = i&1;
    f[ fl ][0] = abs( a[i] - b[0] ) + f[ fl^1 ][0];
    ll mf = f[ fl^1 ][0];
    for ( int j=1; j<nb; j++ )
    {
      mf = min( mf, f[ fl^1 ][j] );
      f[ fl ][j] = mf + abs( a[i] - b[j] );
    }
  }

  ll ans = infLL;
  forn( i, nb )
    ans = min( ans, f[ (n-1)&1 ][i] );

  cout << ans << endl;
}