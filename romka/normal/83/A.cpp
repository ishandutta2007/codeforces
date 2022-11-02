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

int n, a[100010];

int main()
{
  scanf( "%d", &n );
  forn( i, n ) scanf( "%d", &a[i] );

  ll ans = 0;
  forn( i, n ) {
    int j = i;
    for ( j=i; j<n && a[j] == a[i]; j++ );
    ans += (ll)(j-i) * (j-i+1) / 2;
    i = j-1;
  }

  printf( "%I64d\n", ans );

  return 0;
}