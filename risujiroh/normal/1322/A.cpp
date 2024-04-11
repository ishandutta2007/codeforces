#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (2 * count(begin(s), end(s), '(') != n) {
    cout << "-1\n";
  } else {
    int t = 0, res = 0;
    for (char c : s) {
      int nt = t;
      if (c == '(') {
        ++nt;
      } else {
        --nt;
      }
      res += min(t, nt) < 0;
      t = nt;
    }
    cout << res << '\n';
  }
}