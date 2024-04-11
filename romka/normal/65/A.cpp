#include <cstdio>
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

int a, b, c, d, e, f;

bool solve()
{
  if ( d == 0 ) return false;
  if ( c == 0 ) return true;
  if ( b == 0 ) return false;
  if ( a == 0 ) return true;
  if ( f == 0 ) return false;
  if ( e == 0 ) return true;
  return b*d*f > a*c*e;
}

int main()
{
  scanf( "%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f );
  if ( solve() ) printf( "Ron\n" );
  else printf( "Hermione\n" );
  return 0;
}