#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int t = n - 11 >> 1;
  int c = count(begin(s), end(s), '8');
  if (c <= t) return cout << "NO" << '\n', 0;
  c = 0;
  for (int i = 0; i < n; ++i) {
    c += s[i] == '8';
    if (c == t + 1) {
      cout << (i - t <= t ? "YES" : "NO") << '\n';
      return 0;
    }
  }
}