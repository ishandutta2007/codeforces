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

int x, y;

bool solve() {
  while ( true ) {
    if ( x >= 2 && y >= 2 ) x-=2, y-=2;
    else
      if ( x >= 1 && y >= 12 ) x-=1, y-=12;
      else if ( y >= 22 ) y -= 22;
           else return false;

    if ( y >= 22 ) y -= 22;
    else if ( x >= 1 && y >= 12 ) x -= 1, y -= 12;
         else if ( x >= 2 && y >= 2 ) x -= 2, y -= 2;
              else return true;
  }
}

int main()
{
  scanf( "%d %d", &x, &y );
  if ( solve() ) printf( "Ciel\n" );
  else printf( "Hanako\n" );
  return 0;
}