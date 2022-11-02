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

int n, ans[1010];
char s[1230];

int main()
{
  scanf( "%d", &n );
  int lp = 1000;
  bool ok = true;
  forn( i,n )
  {
    scanf( "%s", s );
    int mi = 100000, cur;
    forn( q, 4 )
    {
      char z = s[q];
      forn( j, 10 )
      {
        s[q] = '0' + j;
        sscanf( s, "%d", &cur );
        if ( cur >= lp && cur <= 2011 && cur < mi )
          mi = cur;
      }
      s[q] = z;
    }

    if ( mi < 9999 )
    {
      ans[i] = mi;
      lp = mi;
    }
    else
    {
      ok = false;
    }
  }

  if ( ok )
  {
    forn( i, n ) printf( "%d\n", ans[i] );
  }
  else printf( "No solution\n" );

  return 0;
}