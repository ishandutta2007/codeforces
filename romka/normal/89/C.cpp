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

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, -1, 0, 1 };

const int maxn = 5010;

int n, m;
char a[maxn][maxn];

int ans, ansc, it;
int ci[maxn], cj[maxn];
int next[4][maxn], buf[4][maxn];
int d[maxn];
                                         
int getd( char c ) {
  if ( c == 'U' ) return 0;
  if ( c == 'L' ) return 1;
  if ( c == 'D' ) return 2;
  return 3;
}

int go( int cur ) {
  int res = 0;

  while ( cur != -1 ) {
    res++;
    int ncur = next[ d[cur] ][ cur ];
    if ( next[2][cur] != -1 )
      next[0][ next[2][cur] ] = next[0][cur];
    if ( next[0][cur] != -1 )
      next[2][ next[0][cur] ] = next[2][cur];
    if ( next[3][cur] != -1 )
      next[1][ next[3][cur] ] = next[1][cur];
    if ( next[1][cur] != -1 )
      next[3][ next[1][cur] ] = next[3][cur];
    cur = ncur;
  }

  return res;
}

int main()
{
  scanf( "%d %d", &n, &m );

  forn( i, n )
    scanf( "%s", a[i] );

  ans = 0, ansc = 0;

  int k = 0;
  forn( i, n )
    forn( j, m )
      if ( a[i][j] != '.' ) {
        ci[k] = i;
        cj[k] = j;
        d[k] = getd( a[i][j] );
        k++;
      }

  forn( a, k ) {
    int ml = -1, mr = -1, mu = -1, md = -1;
    forn( b, k ) 
      if ( b != a ) {
        if ( ci[a] == ci[b] ) {
          if ( cj[b] < cj[a] && ( ml == -1 || cj[b] > cj[ml] ) ) ml = b;
          if ( cj[b] > cj[a] && ( mr == -1 || cj[b] < cj[mr] ) ) mr = b;
        }
        if ( cj[a] == cj[b] ) {
          if ( ci[b] < ci[a] && ( mu == -1 || ci[b] > ci[mu] ) ) mu = b;
          if ( ci[b] > ci[a] && ( md == -1 || ci[b] < ci[md] ) ) md = b;
        }
      }
    next[2][a] = md;
    next[0][a] = mu;
    next[1][a] = ml;
    next[3][a] = mr;
  }

  forn( j, 4 )
  forn( i, k ) 
    buf[j][i] = next[j][i];

  forn( i, k ) {
    int z = go( i );
    forn( j, 4 ) forn( i, k ) next[j][i] = buf[j][i];

    if ( z > ans ) {
      ans = z;
      ansc = 1;
    } else
      if ( z == ans ) ansc++;
  }

  printf( "%d %d\n", ans, ansc );

  return 0;
}