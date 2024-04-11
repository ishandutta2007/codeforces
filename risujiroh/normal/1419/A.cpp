#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool win = [&] {
      if (n & 1) {
        for (int i = 0; i < n; i += 2)
          if (s[i] & 1) return true;
        return false;
      } else {
        for (int i = 1; i < n; i += 2)
          if (~s[i] & 1) return false;
        return true;
      }
    }();
    cout << (win ? 1 : 2) << '\n';
  }
}