#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Itr> auto rle(Itr first, Itr last) {
  V< pair<decltype(*first), int> > res;
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    string s; cin >> s;
    set<char> se;
    for (const auto& e : rle(begin(s), end(s))) {
      if (e.second & 1) {
        se.insert(e.first);
      }
    }
    for (char c : se) {
      cout << c;
    }
    cout << '\n';
  }
}