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

const int kMaxN = 1e5;

int c[kMaxN];

void Init() {
  for (int i = 0; i < kMaxN; ++i)
    c[i] = i;
}

int Root(int v) {
  return c[v] == v ? v : c[v] = Root(c[v]);
}

bool Merge(int v, int u) {
  v = Root(v);
  u = Root(u);
  if (v == u)
    return false;
  if (rand() & 1)
    swap(v, u);
  c[v] = u;
  return true;
}

int main() {
#ifdef ssu1
  assert(freopen("input.txt", "rt", stdin));
#endif
  int n, mx, t;
  cin >> n >> mx >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    a[i] = (h * 60 + m) * 60 + s;
  }

  Init();

  int sum = 0, was = 0, it = 0;
  multiset<pair<int, int>> ends;
  for (int x = 0; x <= 60 * 60 * 24; ++x) {
    while (it < a.size() && a[it] == x) {
      ends.insert({a[it] + t - 1, it});
      sum++;
      it++;
    }

    if (ends.size() >= mx) {
      was = true;
      int mergecnt = ends.size() - mx + 1;
      if (mergecnt > 1) {
        pair<int, int> newend = *ends.rbegin();
        multiset<pair<int, int>>::iterator mergeit = ends.end();
        vector<pair<int, int>> del;
        for (int i = 0; i < mergecnt; ++i) {
          --mergeit;
          del.push_back(*mergeit);
        }
        sum += (1 - mergecnt);
        for (int i = 0; i < del.size(); ++i) {
          ends.erase(ends.find(del[i]));
          if (i + 1 < del.size())
            Merge(del[i].second, del[i + 1].second);
        }
        ends.insert(newend);
        assert(ends.size() == mx);
      }
    }

    while (!ends.empty() && ends.begin()->first == x)
      ends.erase(ends.begin());
  }

  if (was) {
    cout << sum << endl;
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
      if (idx.count(Root(i)) == 0) {
        int id = idx.size();
        idx[Root(i)] = id;
      }
      printf("%d\n", idx[Root(i)] + 1);
    }
  } else
    puts("No solution");

#ifdef ssu1
  cerr << "\nTime = " << ((double)clock()) / CLOCKS_PER_SEC << endl;
#endif    
  return 0;
}