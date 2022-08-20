#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int a = 0;
  for (auto c : s) {
    if (c == 'a') {
      ++a;
    }
  }
  int n = s.size();
  if ((n + a) & 1) {
    cout << ":(" << "\n";
    return 0;
  }
  int m = (n + a) / 2;
  string t = s.substr(0, m);
  for (int i = 0; i < m; ++i) {
    if (s[i] != 'a') {
      t.push_back(s[i]);
    }
  }
  cout << (s == t ? s.substr(0, m) : ":(") << "\n";
  return 0;
}