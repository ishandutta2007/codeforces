#include <cstdio>
#include <cstring>
#include <memory.h>
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

const int inf = 1 << 29;

char s[100010], t[100010];
int g[30][30];
int k;
char s1[10], s2[10];
int c;
char as[100010];

int main()
{
  scanf( "%s", s );
  scanf( "%s", t );

  int n = strlen( s );
  int m = strlen( t );

  if ( n != m )
  {
    printf( "-1\n" );
    return 0;
  }

  forn( i, 26 )
    forn( j, 26 )
      g[i][j] = i == j ? 0 : inf;

  scanf( "%d", &k );
  forn( i, k )
  {
    scanf( "%s %s %d", s1, s2, &c );
    int x = s1[0] - 'a';
    int y = s2[0] - 'a';
    g[x][y] = min( g[x][y], c );
  }

  forn( k, 26 )
    forn( j, 26 )
      forn( i, 26 )
        g[i][j] = min( g[i][j], g[i][k] + g[k][j] );

  ll ans = 0;
  forn( i, n )
  {
    int a = s[i] - 'a';
    int b = t[i] - 'a';

    int cur = inf;
    forn( q, 26 )
      if ( g[a][q] + g[b][q] < cur )
      {
        cur = g[a][q] + g[b][q];
        as[i] = 'a' + q;
      }

    if ( cur == inf )
    {
      printf( "-1\n" );
      return 0;
    } 

    ans += cur;
  }
  as[n] = 0;

  cout << ans << endl;
  puts( as );
}