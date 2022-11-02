#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

const int inf = 1 << 22;

int n, m, k, c, r, v[1010];

int main()
{
  scanf( "%d %d %d", &m, &n, &k );

  forn( i, n ) v[i] = inf;

  forn( i, m )
  {
    scanf( "%d %d", &r, &c );
    r--;
    v[r] = min( v[r], c );
  }

  int ans = 0;
  forn( i, n )
    ans += v[i];

  ans = min( ans, k );

  printf( "%d\n", ans );
}