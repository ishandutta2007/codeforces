#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int sum = 0;
    bool foo = false;
    bool bar = false;
    for (auto c : s) {
      sum = (sum + c - '0') % 3;
      if (c == '0') {
        if (foo) {
          bar = true;
        } else {
          foo = true;
        }
      } else if ((c - '0') % 2 == 0) {
        bar = true;
      }
    }
    cout << (foo && bar && sum % 3 == 0 ? "red" : "cyan") << "\n";
  }
  return 0;
}