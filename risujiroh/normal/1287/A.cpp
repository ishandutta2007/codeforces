#include <bits/stdc++.h>
using namespace std;

template <class Itr> auto rle(Itr first, Itr last) {
  vector< pair<decltype(*first), int> > res;
  for (; first != last; ++first) {
    if (res.empty() or res.back().first != *first) {
      res.emplace_back(*first, 1);
    } else {
      ++res.back().second;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    bool first = true;
    for (auto e : rle(begin(s), end(s))) {
      if (not exchange(first, false) and e.first == 'P') {
        res = max(res, e.second);
      }
    }
    cout << res << '\n';
  }
}