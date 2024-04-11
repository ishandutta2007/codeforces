#include <cstdio>
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

int n, a[maxn], b[maxn];
multiset<ll> ss;
vector<int> ans;

void solve( bool flag )
{
  ll mi = 1LL << 40;
  ll sa = 0, sb = 0;
  forn( i, n )
  {
    sa += a[i];
    sb += b[i];
    mi = min( mi, sa-sb );
//    ss.insert( sa-sb );
  }

  ll ca = 0, cb = 0;
  forn( i, n )
  {
//    ll z = *ss.begin();
    if ( mi+cb-ca >= 0 ) ans.pb( flag ? n-i : i+1 );

    ca += a[i];
    cb += b[i];

//    ss.erase( ca-cb );
//    ss.insert( 0 );
  }

}

int main()
{
  scanf( "%d", &n );
  forn( i,n ) scanf( "%d", &a[i] );
  forn( i,n ) scanf( "%d", &b[i] );

  solve( false );

//  forn( i, ans.size() ) printf( "%d ", ans[i] ); printf( "<- \n" );

  reverse( a, a+n );
  reverse( b, b+n );
  int c = b[0];
  forn( i, n-1 ) b[i] = b[i+1];
  b[n-1] = c;

  solve( true );

  sort( ans.begin(), ans.end() );
  ans.resize( unique( ans.begin(), ans.end() ) - ans.begin() );

  printf( "%d\n", ans.size() );
  forn( i,ans.size() )
  {
    if ( i ) printf( " " );
    printf( "%d", ans[i] );
  }

  return 0;
}