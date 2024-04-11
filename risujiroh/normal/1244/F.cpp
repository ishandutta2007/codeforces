#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s += s;
  bool f = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == s[i + 1]) {
      f = false;
      break;
    }
  }
  if (f) {
    if (k & 1) {
      for (auto&& e : s) {
        e ^= 'B' ^ 'W';
      }
    }
    cout << s.substr(0, n) << '\n';
    return 0;
  }
  vector<int> l(2 * n);
  for (int i = 1; i < 2 * n; ++i) {
    if (s[i - 1] != s[i]) {
      l[i] = l[i - 1] + 1;
    }
  }
  vector<int> r(2 * n);
  for (int i = 2 * n - 2; i >= 0; --i) {
    if (s[i] != s[i + 1]) {
      r[i] = 1 + r[i + 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    int mn = min({k, l[n + i], r[i]});
    cout << (char)(mn & 1 ? s[i] ^ 'B' ^ 'W' : s[i]);
  }
  cout << '\n';
}