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

char s1[10010], s2[1000010];
int next[10010][30];

int main()
{
  scanf( "%s", s1 );
  scanf( "%s", s2 );
  int n = strlen( s1 );
  int m = strlen( s2 );

  forn( i, 26 ) next[n][i] = -1;
  for ( int i=n-1; i>=0; i-- ) {
    forn( j, 26 ) next[i][j] = next[i+1][j];
    next[i][ s1[i]-'a' ] = i;
  }
  
  forn( j, m )
    if ( next[0][ s2[j]-'a' ] == -1 ) {
      printf( "-1\n" );
      return 0;
    }

  int i = 0, res = 1;
  forn( j, m ) {
    i = next[i][ s2[j]-'a' ];
    if ( i == -1 ) {
      i = next[0][ s2[j]-'a' ]+1;
      res++;
    } else i++;
//    printf( "-> %d\n", i );
  }

  printf( "%d\n", res );

  return 0;
}