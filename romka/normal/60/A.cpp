#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <memory.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
  int n, m, x;
  char s[120];
  char f[120];
  scanf( "%d %d", &n, &m );
  int toL = n+1, toR = 0;
  forn( i, m ) 
  {
    scanf( "%s %s %s %s %d", f, f, s, f, &x );
    if ( s[0] == 'l' ) toL = min( toL, x );
    else toR = max( toR, x );
  }

  int ans = toL - toR - 1;
  if ( ans <= 0 ) printf( "-1\n" );
  else printf( "%d\n", ans );
  return 0;
}