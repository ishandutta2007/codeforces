#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  V<> cnt(26);
  for (char c : s) {
    if (accumulate(begin(cnt), begin(cnt) + (c - 'a'), 0)) {
      cout << "Ann" << '\n';
    } else {
      cout << "Mike" << '\n';
    }
    ++cnt[c - 'a'];
  }
}