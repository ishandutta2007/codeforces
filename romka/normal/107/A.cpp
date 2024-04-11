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
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, m, a, b, c, wgt[1010], dst[1010], out[1010], in[1010];

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, m ) {
     scanf( "%d %d %d", &a, &b, &c );
     a--, b--;
     dst[a] = b;
     wgt[a] = c;
     out[a]++;
     in[b]++;
  }
  vector<pii> vv;
  vector<int> av;
  forn( i, n )
    if ( in[i] == 0 && out[i] != 0 ) {
       int j = i;
       int ans = 1 << 30;
       while ( out[j] != 0 ) {
         ans = min( ans, wgt[j] );
         j = dst[j];
       }
       vv.pb( pii( i+1, j+1 ) );
       av.pb( ans );
    }
  printf( "%d\n", av.size() );
  forn( i, av.size() )
    printf( "%d %d %d\n", vv[i].first, vv[i].second, av[i] );
  return 0;
}