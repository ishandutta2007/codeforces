#include <cstdio>
#include <utility>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

char s[120][120];
int a[120];

ll op( ll a, ll b, char o )
{
  if ( o == '+' ) return a+b;
  else return a*b;
}

int main()
{
  forn( i, 4 ) scanf( "%d", &a[i] );
  forn( i, 3 ) scanf( "%s", s[i] );

  sort( a, a+4 );

  ll ans = 1LL << 50;

  do {
    ll res = a[0];
    forn( i, 3 )
      if ( s[i][0] == '+' ) res += a[i+1];
      else res *= a[i+1];
    if ( res < ans ) ans = res;

    res = op( a[0], a[1], s[0][0] );
    ll res2 = op( a[2], a[3], s[1][0] );
    res = op( res, res2, s[2][0] );

    if ( res < ans ) ans = res;
  } while ( next_permutation( a, a+4 ) );

  cout << ans << endl;

  return 0;
}