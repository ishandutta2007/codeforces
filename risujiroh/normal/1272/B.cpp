#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int n = s.size();
    int l = count(begin(s), end(s), 'L');
    int r = count(begin(s), end(s), 'R');
    int u = count(begin(s), end(s), 'U');
    int d = count(begin(s), end(s), 'D');
    if (min(l, r) == 0) {
      if (u == 0 or d == 0) {
        cout << "0\n\n";
      } else {
        cout << "2\n";
        cout << "UD\n";
      }
      continue;
    }
    if (min(u, d) == 0) {
      if (l == 0 or r == 0) {
        cout << "0\n\n";
      } else {
        cout << "2\n";
        cout << "LR\n";
      }
      continue;
    }
    cout << 2 * (min(l, r) + min(u, d)) << '\n';
    cout << string(min(l, r), 'L');
    cout << string(min(u, d), 'D');
    cout << string(min(l, r), 'R');
    cout << string(min(u, d), 'U');
    cout << '\n';
  }
}