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

int main()
{
  int a, b;
  scanf( "%d %d", &a, &b );
  int na = a, nb = b;
  ll sa = 0, sb = 0;
  while ( true ) {
    if ( na == nb ) {
      if ( a > b ) sa += na;
      else sb += nb;
      break;
    }
    else
      if ( na < nb ) sa += na, nb -= na, na = a;
      else sb += nb, na -= nb, nb = b;
//    printf( "%d %d, sa=%I64d, sb=%I64d\n", na, nb, sa, sb );
  }
  if ( sa == sb ) printf( "Equal\n" );
  else if ( sa > sb ) printf( "Dasha\n" );
       else printf( "Masha\n" );
  return 0;
}