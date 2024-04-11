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
  sort(begin(s), end(s));
  sort(begin(t), end(t));
  int n = size(s);
  deque<char> a(begin(s), end(s) - n / 2);
  deque<char> b(end(t) - n / 2, end(t));
  DEBUG(a, b);
  string res(n, '?');
  bool first = true;
  int l = 0, r = n;
  while (not empty(a) or not empty(b)) {
    if (first) {
      if (empty(b) or a.front() < b.back()) {
        res[l++] = a.front();
        a.pop_front();
      } else {
        res[--r] = a.back();
        a.pop_back();
      }
    } else {
      if (empty(a) or a.front() < b.back()) {
        res[l++] = b.back();
        b.pop_back();
      } else {
        res[--r] = b.front();
        b.pop_front();
      }
    }
    first ^= true;
  }
  cout << res << '\n';
}