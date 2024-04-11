#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  string res;
  for (int i = 0; i < n / 4; ++i) {
    V<char> v{s[2 * i], s[2 * i + 1], s[n + ~(2 * i)], s[n + ~(2 * i + 1)]};
    for (char c = 'a'; c <= 'c'; ++c) if (count(begin(v), end(v), c) >= 2) {
      res += c;
      break;
    }
  }
  auto t = res;
  reverse(begin(t), end(t));
  if (n % 4) {
    res += s[n / 2];
  }
  res += t;
  cout << res << '\n';
}