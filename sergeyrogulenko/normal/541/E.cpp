#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>
#include <iomanip>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int NMAX = 1100;

vector<int> g[NMAX], l;
int c[NMAX], p[NMAX], d[NMAX], q[NMAX];

void dfs(int v, int col, int part) {
  if (p[v] != -1 && p[v] != part) {
    puts("-1");
    exit(0);
  }
  p[v] = part;
  if (c[v] == col)
    return;
  c[v] = col;
  l.pb(v);

  forn(i, g[v].size())
    dfs(g[v][i], col, part ^ 1);
}

int bfs() {
  int ans = 0;
  forn(i, l.size()) {
    int st = l[i];
    forn(j, l.size())
      d[l[j]] = -1;
    d[st] = 0;
    int sz = 0;
    q[sz++] = st;

    forn(j, sz) {
      int v = q[j];

      ans = max(ans, d[v]);

      forn(t, g[v].size()) {
        int to = g[v][t];
        if (d[to] == -1) {
          d[to] = d[v] + 1;
          q[sz++] = to;
        }
      }
    }
  }
  return ans;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int n, m;
  cin >> n >> m;
  forn(i, m) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    g[v1].pb(v2);
    g[v2].pb(v1);
  }

  int ans = 0, cnt = 0;
  memset(c, -1, sizeof(c));
  memset(p, -1, sizeof(p));
  forn(i, n)
    if (c[i] == -1) {
      l.clear();
      dfs(i, cnt, 0);
      ans += bfs();
      cnt++;
    }

  cout << ans << endl;
  
  return 0;
}