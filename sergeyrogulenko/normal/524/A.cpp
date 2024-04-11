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

map<int, set<int> > g;

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int m, k;
  cin >> m >> k;
  vector<pair<int, int> > e(m);
  vector<int> vs;
  forn(i, m) {
    cin >> e[i].fs >> e[i].sc;
    g[e[i].fs].insert(e[i].sc);
    g[e[i].sc].insert(e[i].fs);
    vs.pb(e[i].fs);
    vs.pb(e[i].sc);
  }

  sort(all(vs));
  vs.erase(unique(all(vs)), vs.end());

  forn(i, vs.size()) {
    int v1 = vs[i];
    vector<int> ans;
    forn(j, vs.size()) {
      if (i == j)
        continue;
      int v2 = vs[j];

      if (g[v1].find(v2) != g[v1].end())
        continue;

      int cnt = 0;
      for (set<int>::iterator it = g[v1].begin(); it != g[v1].end(); it++)
        if (g[v2].find(*it) != g[v2].end())
          cnt++;

      if (cnt * 100 >= k * (int)g[v1].size())
        ans.pb(v2);
    }

    printf("%d: %d", v1, (int)ans.size());
    forn(i, ans.size())
      printf(" %d", ans[i]);
    puts("");
  }


  
  return 0;
}