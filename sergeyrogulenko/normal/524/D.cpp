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

int a[110000], ans[110000];

int main() {
#ifdef RADs_project
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  int n, m, t;
  cin >> n >> m >> t;

  forn(i, n) {
    int x, y, z;
    scanf("%d:%d:%d", &x, &y, &z);
    a[i] = x * 60 * 60 + y * 60 + z;
  }

  set<pair<int, int> > cur;
  int r = 0;
  bool reach = false;
  forn(i, n) {
    while (cur.size() && a[i] - cur.begin()->fs >= t)
      cur.erase(cur.begin());

    int id;
    if ((int)cur.size() < m) {
      r++;
      id = r;
    } else {
      id = (--cur.end())->sc;
      cur.erase(--cur.end());
    }

    cur.insert(mp(a[i], id));

    if ((int)cur.size() == m)
      reach = true;

    ans[i] = id;
  }

  if (!reach)
    puts("No solution");
  else {
    printf("%d\n", r);
    forn(i, n)
      printf("%d\n", ans[i]);
  }

  return 0;
}