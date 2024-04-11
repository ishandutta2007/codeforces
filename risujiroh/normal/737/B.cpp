#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class S> auto rle(const S& s) {
  vector<decltype(make_pair(s[0], 1))> res;
  for (auto c : s)
    if (empty(res) or res.back().first != c) res.emplace_back(c, 1);
    else ++res.back().second;
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  auto v = rle(s);
  int cnt = 0;
  for (auto [c, len] : v) {
    if (c == '1') continue;
    cnt += len / b;
  }
  assert(a <= cnt);
  int need = cnt - a + 1;
  vector<int> res;
  int off = 0;
  for (auto [c, len] : v) {
    if (c == '0') {
      for (int i = b - 1; i < len; i += b) {
        if (need-- > 0) {
          res.push_back(off + i);
        }
      }
    }
    off += len;
  }
  int m = size(res);
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << res[i] + 1 << " \n"[i == m - 1];
  }
}