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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<int> se;
  while (k--) {
    char c;
    cin >> c;
    se.insert(c);
  }
  string t;
  for (int i = 0; i < n; ++i) {
    if (se.count(s[i])) {
      t += '1';
    } else {
      t += '0';
    }
  }
  long long res = 0;
  for (auto e : rle(begin(t), end(t))) {
    if (e.first == '1') {
      res += (long long)e.second * (e.second + 1) / 2;
    }
  }
  cout << res << '\n';
}