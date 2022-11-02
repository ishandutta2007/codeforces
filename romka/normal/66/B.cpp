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

int n, a[1010];

int main()
{
  scanf( "%d", &n );
  forn( i,n ) scanf( "%d", &a[i] );

  int ans = 0;
  forn( i,n )
  {
    int j1 = i, j2 = i;
    while ( j1-1 >= 0 && a[j1-1] <= a[j1] ) j1--;
    while ( j2+1 < n && a[j2+1] <= a[j2] ) j2++;

    if ( j2-j1+1 > ans ) ans = j2-j1 + 1;
  }
  
  printf( "%d\n", ans );
  return 0;
}