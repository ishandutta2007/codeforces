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

char s[3210];
int n;

int check( char* s, char z )
{
  int i = 0, j = n-1, res = 0;
  while ( i < j )
  {
    while ( i < j && s[i] == z ) i++;
    while ( j > i && s[j] != z ) j--;

    if ( i < j )
    {
      i++, j--;
      res++;
    }
  }

  return res;
}

int main()
{
  scanf( "%d", &n );
  scanf( "%s", s );
  forn( i, n ) s[i+n] = s[i];

  int ans = n+2;

  forn( i, n )
    ans = min( ans, min( check( s+i, 'T' ), check( s+i, 'H' ) ) );

  printf( "%d\n", ans );

  return 0;
}