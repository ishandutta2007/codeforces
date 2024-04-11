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

int g[10][10];
int PA[10];
int m, a, b, c, ans1, ans2;
char s1[1230], s2[1230];
map<string,int> mm;

int aa( int x ) {
  return x < 0 ? -x : x;
}

void rec( int i, int c1, int c2, int c3 ) {
  if ( i == 7 ) {
    if ( c1 == 0 || c2 == 0 || c3 == 0 ) return;

    int ac = a/c1;
    int bc = b/c2;
    int cc = c/c3;

    int r1 = max( aa( ac-cc ), aa( ac-bc ) );
    r1 = max( r1, aa( bc-cc ) );

    int r2 = 0;
    forn( i, 7 )
      forn( j, 7 )
        if ( g[i][j] && PA[i] == PA[j] )
          r2++;

    if ( ans1 == -1 || ( r1 < ans1 || (r1 == ans1 && r2 > ans2) ) ) {
      ans1 = r1;
      ans2 = r2;
    }

    return;
  }

  PA[i] = 0;
  rec( i+1, c1+1, c2, c3 );
  PA[i] = 1;
  rec( i+1, c1, c2+1, c3 );
  PA[i] = 2;
  rec( i+1, c1, c2, c3+1 );
}

int main()
{
  mm[ "Anka" ] = 0,
  mm[ "Chapay" ] = 1,
  mm[ "Cleo" ] = 2,
  mm[ "Troll" ] = 3,
  mm[ "Dracul" ] = 4,
  mm[ "Snowy" ] = 5,
  mm[ "Hexadecimal" ] = 6;

  scanf( "%d", &m );
  forn( i, m ) {
    scanf( "%s %*s %s", s1, s2 );
    g[ mm[ string(s1) ] ][ mm[ string(s2) ] ] = 1;
//    g[ mm[ string(s2) ] ][ mm[ string(s1) ] ] = 1;
  }
  scanf( "%d %d %d", &a, &b, &c );

  ans1 = ans2 = -1;
  rec( 0, 0, 0, 0 );

  printf( "%d %d\n", ans1, ans2 );

  return 0;
}