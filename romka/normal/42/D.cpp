#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

int n, a[30][30];
const int f[] = { 288, 434, 152, 375, 304, 82, 439, 195, 103, 156, 109, 458, 115, 118, 194, 447, 344, 318, 493, 256 };

int main()
{
  scanf( "%d", &n );

  forn( i, n )
    forn( j, n )
    {
      a[i][j] += f[i];
      a[j][i] += f[i];
    }

  forn( i, n )
    a[i][i] = 0;

  forn( i, n )
  {
    forn( j, n )
    {
      if ( j ) printf( " " );
      printf( "%d", a[i][j] );
    } 
    printf( "\n" );
  }
}