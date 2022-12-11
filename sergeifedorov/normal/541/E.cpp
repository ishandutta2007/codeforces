#undef NDEBUG
#ifdef ssu1
#endif

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <limits>

using namespace std;

const int kMaxN = 110000;

int n, m;
vector<int> g[kMaxN];

int used[kMaxN];
vector<int> ord;

void No() {
  puts("-1");
  exit(0);
}

bool Bad(int v, int col) {
  if (used[v])
    return used[v] != col;
  used[v] = col;
  ord.push_back(v);
  for (int u : g[v]) {
    if (Bad(u, 3 - col))
      return true;
  }
  return false;
}

const int kInf = 1e9;

int Bfs(int s) {
  vector<int> d(n, kInf);
  queue<int> q;
  q.push(s);
  d[s] = 0;
  int result = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    result = max(result, d[v]);
    for (int u : g[v]) {
      if (d[u] > d[v] + 1) {
        d[u] = d[v] + 1;
        q.push(u);
      }
    }
  }
  return result;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--, u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  int ans = 0;
  for (int v = 0; v < n; ++v) {
    if (used[v])
      continue;
    ord.clear();
    if (Bad(v, 1)) {
      No();
    }
    int curans = 0;
    for (int start : ord) {
      curans = max(Bfs(start), curans);
    }
    ans += curans;
  }

  cout << ans << endl;
#ifdef ssu1
  cerr << "\nTime = " << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}