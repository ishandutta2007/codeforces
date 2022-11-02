#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
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

vector<pii> g[100010];
bool isBridge[100010];
int fup[100010], tin[100010], glTime;
int cc[100010], tc;
vector<int> g2[100010];
vector<int> order, val;
int rmq[200010][19];
int n2[200010];
bool used[100010];
int n, m, x, y;
int where[100010], hh[100010];

void dfsR( int i, int h )
{
  used[i] = true;
  order.pb( i );
  val.pb( h );
  hh[i] = h;
  forn( j, g2[i].size() )
    if (!used[ g2[i][j] ]) {
      dfsR( g2[i][j], h+1 );
      order.pb( i );
      val.pb( h );
    }
}

int getmin( int i, int j )
{
  if ( i > j ) swap( i, j );
  int len = j-i+1;
  int q = n2[len];
  return min( rmq[i][q], rmq[j-(1<<q)+1][q] );
}


void dfs(int v, int p) {
  used[v] = true;
  tin[v] = fup[v] = glTime++;
  forn(i, g[v].size()) {
    int to = g[v][i].first;
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v])
        isBridge[g[v][i].second] = true;
    }
  }
}

void dfsC(int v, int c) {
  cc[v] = c;
  forn(i, g[v].size())
    if (cc[ g[v][i].first ] == 0) {
      if (isBridge[ g[v][i].second ]) {
        tc++;
        dfsC(g[v][i].first, tc);
      } else {
        dfsC(g[v][i].first, c);
      }
    }
}

set<pii> ss;

int main()
{
  scanf("%d %d", &n, &m);
  forn(i, m) {
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(pii(y, i));
    g[y].pb(pii(x, i));
  }
  dfs(0, -1);
  tc = 1;
  dfsC(0, 1);

  forn(i, n)
    forn(j, g[i].size()) {
      if (cc[i] != cc[ g[i][j].first ]) {
        x = cc[i];
        y = cc[ g[i][j].first ];
        x--, y--;
        if (x > y) swap(x, y);
        if (ss.find(pii(x, y)) != ss.end()) continue;
        ss.insert(pii(x, y));
        g2[x].pb(y);
        g2[y].pb(x);
      }
    }

  memset(used, 0, sizeof(used));
  dfsR(0, 0);
  int N = order.size();
  forn(i, order.size()) where[ order[i] ] = i;

  forn( i, N ) rmq[i][0] = val[i];
  forn( j, 18 )
    forn( i, N-(1<<j) )
      rmq[i][j+1] = min( rmq[i][j], rmq[i+(1<<j)][j] );

  n2[1] = 0;
  for ( int i=2; i<=N; i++ ) n2[i] = ( n2[i>>1] + 1 );

  int k;
  scanf("%d", &k);
  forn(i, k) {
    scanf("%d %d", &x, &y);
    x--, y--;
    x = cc[x] - 1, y = cc[y] - 1;
    int hlca = getmin(where[x], where[y]);
    printf("%d\n", hh[x] + hh[y] - 2 * hlca);
  }

  return 0;
}