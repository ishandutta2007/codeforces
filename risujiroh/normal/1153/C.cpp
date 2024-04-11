#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  if (n & 1) return cout << ":(" << '\n', 0;
  if (s[0] == ')' or s.back() == '(') return cout << ":(" << '\n', 0;
  if (n == 2) return cout << "()" << '\n', 0;
  if (s[1] == ')' or s[n - 2] == '(') return cout << ":(" << '\n', 0;
  int l = count(begin(s), end(s), '(');
  int r = count(begin(s), end(s), ')');
  if (2 * l > n or 2 * r > n) return cout << ":(" << '\n', 0;
  l = n / 2 - l;
  r = n / 2 - r;
  for (int i = 0; i < n; ++i) if (s[i] == '?') {
    if (!l) break;
    s[i] = '(';
    --l;
  }
  assert(!l);
  for (int i = n - 1; i >= 0; --i) if (s[i] == '?') {
    if (!r) break;
    s[i] = ')';
    --r;
  }
  assert(!r);
  assert(!count(begin(s), end(s), '?'));
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') ++t;
    else --t;
    if (i != n - 1 and t <= 0) return cout << ":(" << '\n', 0;
  }
  assert(!t);
  cout << s << '\n';
}