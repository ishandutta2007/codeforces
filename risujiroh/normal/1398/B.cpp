#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

template <class S>
auto rle(const S& s) {
  vector<decltype(make_pair(s[0], 1))> res;
  for (auto c : s)
    if (empty(res) or res.back().first != c)
      res.emplace_back(c, 1);
    else
      ++res.back().second;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> v;
    for (auto [c, len] : rle(s)) {
      if (c == '0') continue;
      v.push_back(len);
    }
    sort(begin(v), end(v), greater<>());
    int res = 0;
    for (int i = 0; i < (int)size(v); i += 2) {
      res += v[i];
    }
    cout << res << '\n';
  }
}