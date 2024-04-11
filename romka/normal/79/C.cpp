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

char s[maxn];
int f[maxn];
char word[15][15];
int len[15];
int m;

int main()
{
  scanf( "%s", s );
  int n = strlen( s );
  scanf( "%d", &m );
  forn( i, m ) {
    scanf( "%s", word[i] );
    len[i] = strlen( word[i] );
  }

  forn( i, n ) {
    f[i] = n;
    forn( j, m )
      if ( i+len[j] <= n ) {
        bool ok = true;
        forn( q, len[j] )
          if ( s[i+q] != word[j][q] ) {
            ok = false;
            break;
          }
        if ( ok ) f[i] = min( f[i], i+len[j]-1 );
      }
//    printf( "%d ", f[i] );
  }


  int ans = 0, ap = 0, lp = n;
  for ( int i=n-1; i>=0; i-- ) {
    lp = min( lp, f[i] );
    if ( lp-i > ans ) {
      ans = lp-i;
      ap = i;
    }
  }

  printf( "%d %d\n", ans, ap );

  return 0;
}