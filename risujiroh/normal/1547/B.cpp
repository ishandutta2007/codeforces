#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = size(s);
    cout << ([&] {
      for (int i = n; i--;) {
        if (s[0] == 'a' + i) {
          s.erase(begin(s));
          continue;
        }
        if (s.back() == 'a' + i) {
          s.pop_back();
          continue;
        }
        return false;
      }
      return true;
    }()
                 ? "Yes\n"
                 : "No\n");
  }
}