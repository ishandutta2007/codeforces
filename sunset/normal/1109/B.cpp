#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = (int) s.size();
  bool same = true;
  for (int i = 0; i < n; ++i) {
    if (n % 2 == 0 || i != n / 2) {
      if (s[i] != s[0]) {
        same = false;
        break;
      }
    }
  }
  if (same) {
    cout << "Impossible" << "\n";
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    string t = s.substr(i, n - i) + s.substr(0, i);
    string rev_t = t;
    reverse(rev_t.begin(), rev_t.end());
    if (s != t && t == rev_t) {
      cout << 1 << "\n";
      return 0;
    }
  }
  cout << 2 << "\n";
  return 0;
}