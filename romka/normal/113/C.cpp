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
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int N = (int)3e8 + 2;

int l, r;
unsigned char bits[N/16 + 1];

inline bool isset( int x ) {
  x >>= 1;
  int ind = x >> 3;
  int sh = x & 7;
  return bits[ind] & ( 1 << sh );
}

inline void setbit( int x ) {
  x >>= 1;
  int ind = x >> 3;
  int sh = x & 7;
  bits[ind] |= ( 1 << sh );
}

void erat() {
  for ( int i=3; i*i < N; i+=2 )
    if ( !isset( i ) )
      for ( int j=i*i; j < N; j += i+i )
        setbit( j );
}

int main()
{
  erat();
  scanf( "%d %d", &l, &r );
  int ans = 2 >= l && 2 <= r;
  for ( int q=5; q < N; q += 4 )
    ans += q >= l && q <= r && !isset( q );
  printf( "%d\n", ans );
  return 0;
}