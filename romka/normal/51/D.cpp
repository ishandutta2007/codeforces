#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <memory.h>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, a[100010];

bool test( int i, int j, int k )
{
  if ( a[i] == 0 ) return a[j] == 0 && a[k] == 0;
  return a[j]*a[j] == a[k]*a[i];
}

int solve()
{
  bool ok = true;
  forn( i, n )
    if ( a[i] != a[0] )
    {
      ok = false;
      break;
    }

  if ( ok ) return 0;
  if ( n == 2 ) 
    if ( a[0] != 0 ) return 0;
    else return 1;

  int i = 1;
  while ( i < n-1 && test( i-1, i, i+1 ) ) i++;
  int j = n-2;
  while ( j > 0 && test( j-1, j, j+1 ) ) j--;

//  printf( "-> %d %d\n", i, j );

  if ( i == n-1 ) return 0;
  if ( i == n-2 || j == 1 ) return 1;
  if ( i+2 == j && test( i-1, i, j ) && test( i, j, j+1 ) ) return 1;
  if ( i+1 == j && test( i-1, i, j+1 ) && ( j+2 >= n || test( i, j+1, j+2 ) ) ) return 1;
  if ( i+1 == j && ( i-2 < 0 || test( i-2, i-1, j ) ) && test( i-1, j, j+1 ) ) return 1;

  return 2;
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );

  printf( "%d\n", solve() );
}