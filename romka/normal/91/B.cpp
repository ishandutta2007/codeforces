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
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 100010;

int n, a[maxn], ans[maxn];
pii ev[maxn];
set<int> ss;

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] ), ev[i] = pii( a[i], i );

  sort( ev, ev+n );

  for ( int i=0; i<n; ) {
    int j = i;
    for ( ; j < n && ev[i].first == ev[j].first; j++ );
    if ( ss.empty() ) {
      for ( int q=i; q<j; q++ ) {
        ans[ ev[q].second ] = -1;
        ss.insert( ev[q].second );
      }
    } else {
      int r = *ss.rbegin();
      for ( int q=i; q<j; q++ ) {
        if ( ev[q].second < r ) ans[ ev[q].second ] = r - ev[q].second - 1;
        else ans[ ev[q].second ] = -1;
        ss.insert( ev[q].second );
      }
    }

    i = j;
  }

  forn( i, n ) {
    if ( i ) printf( " " );
    printf( "%d", ans[i] );
  }


  return 0;
}