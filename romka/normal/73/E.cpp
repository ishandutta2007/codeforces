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

const int MAX = 1300000;

int n, x, a[100010];
bool u[MAX+5];

int solve() {
  if ( x == 2 ) return 0;
  if ( a[0] == 1 ) return 1;

  for ( int i=2; i*i <= MAX; i++ )
    if ( !u[i] )
      for ( int j=i*i; j <= MAX; j += i )
        u[j] = 1;

  int res = 0;
  int ka = 0;
  int lim = min( MAX, x );
  if ( lim&1 ) lim--;
  for ( int i=2; i <= lim; i++ )
    if ( !u[i] ) {
      while ( ka < n && a[ka] < i ) ka++;
      if ( ka == n || a[ka] != i ) return -1;
      ka++;
      res++;
    }

  return res;  
}

int main()
{
  scanf( "%d %d", &n, &x );
  forn( i, n ) scanf( "%d", &a[i] );

  sort( a, a+n );

  printf( "%d\n", solve() );

  return 0;
}