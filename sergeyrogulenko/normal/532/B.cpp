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

const int NMAX = 210000;

int p[NMAX], a[NMAX];
vector<int> g[NMAX];
vector<int64> z[NMAX][2][2];

int64 rec(int v, int o, int xo, int pos) {
  if (pos == (int)g[v].size()) {
    if (xo == 0 && o == 1)
      return a[v];
    if (o == 1)
      return -INF64;
    return 0;
  }

  if (z[v][o][xo][pos] != -1)
    return z[v][o][xo][pos];

  int64 ans = -INF64;

  forn(no, 2)
    ans = max(ans, rec(g[v][pos], no, 0, 0) + rec(v, o ^ no, xo ^ no, pos + 1));

  if (ans < 0)
    ans = -INF64;

  return z[v][o][xo][pos] = ans;
}

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int n;
  cin >> n;
  forn(i, n) {
    scanf("%d%d", &p[i], &a[i]);
    p[i]--;
  }

  forn(i, n)
    if (p[i] >= 0)
      g[p[i]].pb(i);

  forn(i, n)
    forn(j, 2)
      forn(t, 2)
        z[i][j][t].resize(g[i].size(), -1);

  int64 ans = max(rec(0, 0, 0, 0), rec(0, 1, 0, 0));

  cout << ans << endl;
  
  return 0;
}