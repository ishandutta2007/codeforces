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

int n, m, h, s[1010];
vector<int> a1, a2;

double solve() {
   int all = 0;
   forn( i, m ) all += s[i];
   if ( all < n ) return -1;
   if ( n == 0 ) return 0;   
   int sh = s[h];
   if ( sh == 0 ) return 0;
   if ( all-sh < n ) return 1;

   ld res = 1.0;
   forn( i, all-sh ) a1.pb( i+1 );
   forn( i, all-n ) a1.pb( i+1 );
   forn( i, all ) a2.pb( i+1 );
   forn( i, all-sh-n ) a2.pb( i+1 );

   sort( a1.begin(), a1.end() );
   sort( a2.begin(), a2.end() );

   forn( i, a1.size() ) res *= a1[i] * 1.0 / a2[i];

   return 1.0 - res;
}

int main()
{
  scanf( "%d %d %d", &n, &m, &h );
  forn( i, m ) scanf( "%d", &s[i] );
  h--;
  s[h]--;
  n--;
  printf( "%.9f\n", solve() );
  return 0;
}