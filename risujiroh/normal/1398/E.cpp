#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;
using namespace __gnu_pbds;

template <class Key, class Compare = less<Key>>
using ordered_set = tree<Key, null_type, Compare, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int y = 0;
  ordered_set<int, greater<>> se;
  map<int, int> mp;
  long long base = 0, sum = 0;
  set<int> s, lo, hi;
  while (n--) {
    int tp, d;
    cin >> tp >> d;
    base += d;
    if (d < 0) {
      se.erase(-d);
      if (tp == 0) s.erase(-d);
      if (lo.count(-d)) {
        lo.erase(-d);
      } else {
        sum -= -d;
        hi.erase(-d);
      }
    } else {
      mp[d] = 0;
      se.insert(d);
      if (tp == 0) s.insert(d);
      if (empty(lo) or d > *rbegin(lo)) {
        hi.insert(d);
        sum += d;
      } else {
        lo.insert(d);
      }
    }
    if (tp) {
      if (d < 0) {
        --y;
      } else {
        ++y;
      }
    }
    while ((int)size(hi) < y) {
      sum += *rbegin(lo);
      hi.insert(*rbegin(lo));
      lo.erase(*rbegin(lo));
    }
    while ((int)size(hi) > y) {
      sum -= *begin(hi);
      lo.insert(*begin(hi));
      hi.erase(begin(hi));
    }
    DUMP(lo, hi);
    DUMP(base, sum, y);
    auto res = base + sum;
    if (empty(s) or *rbegin(s) < *se.find_by_order(y - 1)) {
      res -= *se.find_by_order(y - 1);
      res += (empty(s) ? 0 : *rbegin(s));
    }
    cout << res << '\n';
  }
}