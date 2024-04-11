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

char s[1230];

ll get( int x ) {
  sprintf( s, "%d", x );
  int q = strlen( s );
  ll cur = 0;
  forn( i, q ) cur = cur * 10 + ( 9 - s[i] + '0' );
  return cur * x;
}

int l, r;
ll ans;

int main()
{
  scanf( "%d %d", &l, &r );
  ans = -1;
  int zl = l / 100000;
  int zr = r / 100000;
  for ( int i=zl*100000; i<(zl+1)*100000; i++ )
    if ( i >= l && i <= r ) ans = max( ans, get( i ) );
  for ( int i=zr*100000; i<(zr+1)*100000; i++ )
    if ( i >= l && i <= r ) ans = max( ans, get( i ) );
  for ( int q=zl+1; q<zr; q++ ) {
    int a = q * 100000;
    if ( a >= l && a <= r ) ans = max( ans, get( a ) );
    a += 99999;
    if ( a >= l && a <= r ) ans = max( ans, get( a ) );
  }

  printf( "%I64d\n", ans );

  return 0;
}