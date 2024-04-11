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
char a[5][110];

int main()
{
  scanf( "%d", &n );
  int c = 0;
  int k = n - 1;
  a[1][0] = a[0][0] = 'a';
  int z = 0;
  forn( i, k ) {
    if ( i & 1 ) {
      c = ( c+1 ) % 26;
      a[0][z] = a[0][z+1] = 'a' + c;
      c = ( c+1 ) % 26;
      a[1][z] = a[1][z+1] = 'a' + c;
    } else {
      c = ( c+1 ) % 26;
      a[2][z] = a[2][z+1] = 'a' + c;
      c = ( c+1 ) % 26;
      a[3][z] = a[3][z+1] = 'a' + c;
    }
    z++;
  }
  if ( n&1 ) {
      z = n-1;
      c = ( c+1 ) % 26;
      a[2][z] = a[2][z+1] = 'a' + c;
      a[3][z] = a[3][z+1] = 'a' + c;
  } else {
      z = n-1;
      c = ( c+1 ) % 26;
      a[0][z] = a[0][z+1] = 'a' + c;
      a[1][z] = a[1][z+1] = 'a' + c;
  }

  forn( i, 4 ) {
    forn( j, n ) printf( "%c", a[i][j] );
    printf( "\n" );
  } 

  return 0;
}