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

double solve( int a, int b ) {
  if ( b == 0 ) return 1;
  if ( a == 0 ) return 0.5;
  double aa = a;
  double bb = b;
  double x = bb * 4; //0.25;
  double h = min( x, aa ) * 0.25;
  double area = bb * aa + min( x, aa ) * h * 0.5 + ( aa - min( x, aa ) ) * bb;
  return area / ( 2.0 * aa * bb );
}

int main()
{
  int tc, a, b;
  scanf( "%d", &tc );
  while ( tc-- ) {
    scanf( "%d %d", &a, &b );
    printf( "%.10f\n", solve( a, b ) );
  }
  return 0;
}