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

int n, q, a[maxn], b[maxn], l[maxn], r[maxn], t[maxn];
vector<pii> segs;
vector<pii> ev[400];

void naive() {
  forn( i, q ) {
    int mi = -1;
    ll mv = -1;
    for ( int j=l[i]; j<=r[i]; j++ ) {
      ll cur = a[j] + (ll)t[i] * (ll)b[j];
      if ( cur >= mv ) mv = cur, mi = j;
    }
    printf( "%d\n", mi+1 );
  }
}

void process( pii S, int id ) {
  int L = S.first;
  int R = S.second;

  ll mv = -1, mi = -1;
  for ( int i=L; i<R; i++ )
    if ( a[i] > mv ) mv = a[i], mi = i;

  ev[id].pb( pii( 0, mi ) );

  while ( true ) {
    ll mint = (ll)1e17;
    int nmi = -1;
    for ( int i=L; i<R; i++ )
      if ( i != mi && b[i] > b[mi] ) {
        // a[mi] + b[mi] * t < a[i] + b[i] * t
        // a[mi] - a[i] < (b[i] - b[mi])* t
        // (a[mi] - a[i]) / (b[i] - b[mi]) < t
        ll t = ( a[mi]-a[i] ) / ( b[i]-b[mi] );
        while ( a[mi] + t*b[mi] > a[i] + t*b[i] ) t++;
        if ( t < mint || ( t == mint && a[i] + t*b[i] > a[nmi] + t*b[nmi] ) ) {
          mint = t;
          nmi = i;
        }
      }
    if ( nmi == -1 ) break;
    ev[id].pb( pii( (int)mint, nmi ) );
    mi = nmi;
  }
/*
  printf( "seg %d:", id );
  forn( q, ev[id].size() ) printf( " (t=%d,i=%d)", ev[id][q].first, ev[id][q].second );
  printf( "\n" );
*/
}

bool better( int ni, int wi, ll tt ) {
  if ( wi == -1 ) return true;
  return a[wi] + (ll)b[wi] * tt < a[ni] + (ll)b[ni] * tt;
}

int getseg( vector<pii>& ev, int t ) {
  pii sf( t, n+10 );
  int q = upper_bound( ev.begin(), ev.end(), sf ) - ev.begin();
  q--;
  return ev[q].second;
} 

void unittest() {
  vector<pii> ev;
  ev.pb( pii( 0, 1 ) );
  ev.pb( pii( 4, 2 ) );
  ev.pb( pii( 7, 3 ) );
  forn( i, 9 ) printf( "%d -> %d\n", i, getseg( ev, i ) );
}

int main()
{
//  freopen( "e.out", "w", stdout );
  scanf( "%d %d", &n, &q );
  forn( i, n ) scanf( "%d %d", &a[i], &b[i] );
  forn( i, q ) scanf( "%d %d %d", &l[i], &r[i], &t[i] ), l[i]--, r[i]--;

  if ( n < 10 ) {
    naive();
    return 0;
  }

  int sz = (int)( sqrt(1.0*n) + 0.5 );

  int i = 0;
  while ( i < n ) {
    int j = i + sz;
    if ( j > n ) j = n;
    segs.pb( pii( i, j ) );
    i = j;
  }

  forn( i, segs.size() ) process( segs[i], i );

  forn( i, q ) { 
    int res = -1;
    forn( j, segs.size() )
      if ( segs[j].first >= l[i] && segs[j].second <= r[i]+1 ) {
        int z = getseg( ev[j], t[i] );
//        printf( "get from seg %d [%d %d), best is %d\n", j, segs[j].first, segs[j].second, z );
        if ( better( z, res, t[i] ) )
          res = z;
      }
      else 
        if ( ( l[i] >= segs[j].first && l[i] < segs[j].second ) ||
             ( r[i] >= segs[j].first && r[i] < segs[j].second ) ) { 
               int st = max( segs[j].first, l[i] ); 
               int fin = min( segs[j].second-1, r[i] );
               for ( int w = st; w <= fin; w++ )
                 if ( better( w, res, t[i] ) )
                   res = w;
             }
    printf( "%d\n", res+1 );
//    printf( "%I64d\n", a[res] + (ll)b[res] * t[i] );
  }

  return 0;
}