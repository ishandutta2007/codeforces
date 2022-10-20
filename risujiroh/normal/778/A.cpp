#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = size(s);
  vector<int> p(n);
  for (auto&& e : p) cin >> e, --e;
  auto chk = [&](int m) {
    vector idx(begin(p) + m, end(p));
    sort(begin(idx), end(idx));
    string ss;
    for (int i : idx) {
      ss += s[i];
    }
    auto it = begin(t);
    for (char c : ss) {
      if (c == *it) {
        ++it;
      }
    }
    return it == end(t);
  };
  int ok = 0, ng = n;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}