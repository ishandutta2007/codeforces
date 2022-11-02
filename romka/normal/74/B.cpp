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

bool u[210][52][2];
int n, m, k, T, f[210][52][2];
bool head;
char buf[21];
char s[210];
int c[210];

int get( int i, int z, int turn ) {
  if ( z == c[i] ) return i;
  if ( i == T-1 ) return T+5;

  int& res = f[i][z][turn];
  if ( u[i][z][turn] ) return res;
  u[i][z][turn] = true;
  res = 0;

  if ( turn == 0 ) {
    if ( s[i] == '0' ) {
      if ( z > 0 ) {
        res = max( res, get( i, z-1, 1 ) );
      }
      if ( z < n-1 ) {
        res = max( res, get( i, z+1, 1 ) );
      }
      res = max( res, get( i, z, 1 ) );
    } else {
      forn( q, n )
        res = max( res, get( i+1, q, 0 ) );
    }
  } else {
    if ( c[i+1] == z ) return res = i;
    res = get( i+1, z, 0 );
  }

  return res;
}


int main()
{
  scanf( "%d %d %d", &n, &m, &k );
  scanf( "%*s %s", buf );
  if ( buf[0] == 'h' ) head = true;
  else head = false;
  m--, k--;

  scanf( "%s", s );
  T = strlen( s );

  c[0] = k;
  for ( int i=1; i<=T; i++ )
    if ( head ) {
      c[i] = c[i-1] - 1;
      if ( c[i] < 0 ) c[i] = 1, head = false;
    } else {
      c[i] = c[i-1] + 1;
      if ( c[i] >= n ) c[i] = n-2, head = true;
    }

//  forn( i, T ) printf( "%d ", c[i] ); printf( "\n" );

  int res = get( 0, m, 0 );
  if ( res > T+2 ) printf( "Stowaway\n" );
  else printf( "Controller %d\n", res+1 );

  return 0;
}