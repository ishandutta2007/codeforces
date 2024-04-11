#include <bits/stdc++.h>
using namespace std;

template<class Itr> auto rle(Itr first, Itr last) {
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
    vector<int> p(n);
    for (auto&& e : p) {
      cin >> e;
    }
    auto v = rle(begin(p), end(p));
    int m = v.size();
    int g = v[0].second, s = 0, b = 0;
    int i = 1;
    while (i < m and s <= g) {
      s += v[i].second;
      ++i;
    }
    while (i < m and b <= g) {
      b += v[i].second;
      ++i;
    }
    if (g + s + b > n / 2) {
      cout << "0 0 0\n";
      continue;
    }
    while (i < m and g + s + b + v[i].second <= n / 2) {
      b += v[i].second;
      ++i;
    }
    cout << g << ' ' << s << ' ' << b << '\n';
  }
}