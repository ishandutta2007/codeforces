#include <cstdio>
#include <utility>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

int n;
bool u[1010];

int main()
{
  scanf( "%d", &n );

  // if ( n == 1 || (n&(n-1)) == 0 ) printf( "YES\n" ); else printf( "NO\n" );

  int cur = 0;
  u[cur] = 1;
  forn( q, n*n+2 )
  {
    cur += q+1;
    cur %= n;
    u[cur] = 1;
  }

  forn( q, n )
    if ( !u[q] )
    {
      printf( "NO\n" );
      return 0;
    }

  printf( "YES\n" );

  return 0;
}