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

const int maxn = 100010;

multiset<ll> ss;
int k1, k2, k3, t1, t2, t3, b[maxn], n;
ll a[maxn];

void go( int k1, int t1 ) {
  ss.clear();
  forn( i, k1 ) ss.insert( 0 );
  forn( i, n ) {
    ll mm = *ss.begin();
    ss.erase( ss.begin() );
    a[i] = max( a[i], mm ) + t1;
    ss.insert( a[i] );
  }
}

int main()
{
  scanf( "%d %d %d", &k1, &k2, &k3 );
  scanf( "%d %d %d", &t1, &t2, &t3 );
  scanf( "%d", &n );
  forn( i, n ) {
    scanf( "%d", &b[i] );
    a[i] = b[i];
  }
  if ( k1 > n ) k1 = n;
  if ( k2 > n ) k2 = n;
  if ( k3 > n ) k3 = n;

  go( k1, t1 );
  go( k2, t2 );
  go( k3, t3 );

  ll ans = 0;
  forn( i, n ) 
    if ( a[i] - b[i] > ans ) {
      ans = a[i] - b[i];
    }

  printf( "%I64d\n", ans );

  return 0;
}