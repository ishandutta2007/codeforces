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

const int di[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int dj[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int n, m;
bool a[1010][1010];
char s[1010];
bool u[1010][1010];
int u1[1010][1010], it;
int u2[1010][1010];
vector<pii> v1;
pii q[1010*1010];
int qb, qf;

int go( int i, int j ) {
  u2[i][j] = it;
  int res = 1;
  forn( q, 4 ) {
    int ni = i + di[q];
    int nj = j + dj[q];
    if ( ni >= 0 && ni < n && nj >= 0 && nj < m )
      if ( a[ni][nj] == 1 && u1[ni][nj] == it && u2[ni][nj] != it )
        res += go( ni, nj );
  }
  return res;
}

int check( int si, int sj ) {
  qb = qf = 0;
  q[qf++] = pii( si, sj );
  u[si][sj] = 1;
  v1.clear();
  bool side = false;

  it++;
  pii cur;
  while ( qb < qf ) {
    cur = q[qb++];
    si = cur.first;
    sj = cur.second;

    forn( w, 8 ) {
      int ni = si + di[w];
      int nj = sj + dj[w];

      if ( ni < 0 || ni >= n || nj < 0 || nj >= m ) {
        side = true;
        break;
      }
      else
        if ( a[ni][nj] == 1 ) {
          if ( u1[ni][nj] != it ) {
            u1[ni][nj] = it;
            v1.pb( pii( ni, nj ) );
          }
        }
        else
          if ( !u[ni][nj] ) {
            u[ni][nj] = 1;
            q[qf++] = pii( ni, nj );
          }
    }
  }

  if ( side ) return 0;

  forn( i, v1.size() ) {
    int cnt = 0;
    forn( j, 4 ) {
      int ti = v1[i].first + di[j];
      int tj = v1[i].second + dj[j];
      if ( ti >= 0 && ti < n && tj >= 0 && tj < m && a[ti][tj] == 1 && u1[ti][tj] == it )
        cnt++;
    }
    if ( cnt != 2 ) return 0;
  }

  if ( v1.size() )
    if ( go( v1[0].first, v1[0].second ) == (int)v1.size() ) return v1.size();

  return 0;
}

int main()
{
  scanf( "%d %d", &n, &m );
  forn( i, n ) {
    scanf( "%s", s );
    forn( j, m )
      a[i][j] = s[j] == '1';
  }

  int ans = 0;
  forn( i, n-1 )
    forn( j, m-1 )
      if ( a[i][j] && a[i+1][j] && a[i+1][j+1] && a[i][j+1] )
        ans = 4;

  forn( i, n )
    forn( j, m )
      if ( a[i][j] == 0 && !u[i][j] ) {
        int z = check( i, j );
        if ( z > ans ) ans = z;
      }

  printf( "%d\n", ans );
  return 0;
}