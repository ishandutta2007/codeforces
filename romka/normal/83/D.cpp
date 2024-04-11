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

const int N = 1600000;

bool isSimple( int x ) {
  if ( x == 1 ) return false;
  for ( int i=2; i*i <= x; i++ )
    if ( x%i == 0 ) return false;
  return true;
}

bool u[N+5];
vector<int> pp;
ll ans;
int a, b, k;

void rec( int i, ll cur, bool flag ) {
  if ( flag ) ans -= b/cur - (a-1)/cur;
  else ans += b/cur - (a-1)/cur;
  for ( int j=i; j<(int)pp.size(); j++ ) {
    if ( cur*pp[j] > b ) break;
    rec( j+1, cur*pp[j], flag ^ 1 );
  }
}

int main()
{
  scanf( "%d %d %d", &a, &b, &k );

  if ( !isSimple( k ) ) {
    printf( "0\n" );
    return 0;
  }

  if ( k > 45000 ) {
    if ( k >= a && k <= b ) printf( "1\n" );
    else printf( "0\n" );

    return 0;
  }

  for ( int i=2; i*i < N; i++ )
    if ( !u[i] )
      for ( int j=i*i; j < N; j += i )
        u[j] = true;

  if ( k > 1290 ) {
    int ans = k >= a && k <= b;
    for ( int z=k; k*z <= b; z++ )
      if ( !u[z] && k*z >= a ) ans++;
    printf( "%d\n", ans );

    return 0;
  }

  for ( int i=2; i<k; i++ )
    if ( !u[i] ) pp.pb( i );

  ans = 0;
  rec( 0, k, 0 );

  printf( "%d\n", (int)ans );

  return 0;
}