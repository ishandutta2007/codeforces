#undef NDEBUG

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

bool Friend(map<int, set<int>>& g, int id1, int id2) {
  return g[id1].count(id2) > 0;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int m, k;
  cin >> m >> k;
  map<int, set<int>> g;
  set<int> ids;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
    ids.insert(x);
    ids.insert(y);
  }

  for (auto id : ids) {
    vector<int> ans;
    for (auto pat : ids) {
      if (Friend(g, id, pat) || pat == id)
        continue;
      int cnt = 0;
      for (auto mid : g[id]) {
        if (Friend(g, pat, mid))
          cnt++;
      }
      if (k * g[id].size() <= cnt * 100) {
        ans.push_back(pat);
      }
    }
    printf("%d: %d", id, (int)ans.size());
    for (auto x : ans) {
      printf(" %d", x);
    }
    puts("");
  }

#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}