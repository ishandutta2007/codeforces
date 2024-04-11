#include <iostream>
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
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, a[100010];

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );
  sort( a, a+n );
  if ( a[n-1] == 1 ) a[n-1] = 2; else a[n-1] = 1;
  sort( a, a+n );
  forn( i, n ) {
    if ( i ) printf( " " );
    printf( "%d", a[i] );
  }
  return 0;
}