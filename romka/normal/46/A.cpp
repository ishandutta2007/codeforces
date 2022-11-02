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

int main()
{
  int n, cur = 0;
  scanf( "%d", &n );
  forn( q, n-1 )
  {
    cur = ( cur + q + 1 ) % n;
    if ( q ) printf( " " );
    printf( "%d", cur+1 );
  }

  return 0;
}