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

int n;
ll a[55];

int main()
{
  scanf( "%d", &n );
  if ( n == 2 ) printf( "-1\n" );
  else
  {
    a[0] = 6;
    a[1] = 10;
    a[2] = 15;
    a[3] = 30;
    for ( int i=4; i<n; i++ )
      a[i] = a[i-1] * 2;

    forn( i, n )
      printf( "%I64d\n", a[i] );
  }

  return 0;
}