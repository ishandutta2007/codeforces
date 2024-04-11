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

int n;
char s1[1230], s2[1230], s3[1230];
map<string,int> mm;

int main()
{
  scanf( "%d", &n );
  mm[ "void" ] = 0;
  mm[ "errtype" ] = -1;
  forn( i, n ) {
    scanf( "%s %s", s1, s2 );
    if ( strlen(s1) == 6 ) {
      int i = 0;
      int len = strlen( s2 );
      int j = len;
      while ( s2[i] == '&' ) i++;
      while ( s2[j-1] == '*' ) j--;
      s2[j] = 0;
      string s( s2+i );
//      printf( "new type = %s\n", s.c_str() );
      int k = mm.count( s ) ? mm[s] : -1;
//      printf( "k = %d\n", k );
      if ( k < 0 ) printf( "errtype\n" );
      else {
        k += len - j - i;
        if ( k < 0 ) printf( "errtype\n" );
        else {
          printf( "void" );
          forn( q, k ) printf( "*" );
          printf( "\n" );
        }
      }
    } else {
      scanf( "%s", s3 );
      int i = 0;
      int len = strlen( s2 );
      int j = len;

      while ( s2[i] == '&' ) i++;
      while ( s2[j-1] == '*' ) j--;
//      printf( "%d %d %d\n", i, j, strlen( s2 ) );
      s2[j] = 0;
      string s( s2+i );
      int k = mm.count( s ) ? mm[s] : -1;
      if ( k < 0 ) mm[ string(s3) ] = -1;
      else {
//        printf( "k was %d\n", k );
        k += len - j - i;
//        printf( "%s <- %d\n", s3, k );
        if ( k < 0 ) k = -1;
        mm[ string(s3) ] = k;
      }
    }
  }
  return 0;
}