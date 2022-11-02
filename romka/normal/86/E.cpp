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

const int co[] = { 3, 3, 3, 3, 15, 27, 15, 29, 27, 27, 23, 83, 27, 43, 23, 45, 15, 39, 39, 83, 39, 57, 43, 27, 15, 71, 39, 83, 23, 83, 15, 197, 83, 281, 387, 387, 83, 99, 147, 57, 15, 153, 89, 101, 27, 449, 51, 657, 113, 29, 75, 75, 71, 329, 71, 149, 45, 99, 149, 53, 39, 105, 51, 27, 27, 833, 39, 163, 101, 43, 43, 1545, 29 };

int k, a[120];

int main()
{
  scanf( "%d", &k );
  int z = co[k-1];
  forn( i, k ) {
    a[i] = z & 1;
    z >>= 1;
  }

  for ( int i=k-1; i>=0; i-- ) {
    if ( i < k-1 ) printf( " " );
    printf( "%d", a[i] );     
  }
  printf( "\n" );

  forn( i, k ) {
    if ( i ) printf( " " );
    printf( "%d", i == 0 );
  }
  return 0;
}