#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    bool ok = [&] {
      int zero = count(begin(s), end(s), '0');
      if (zero == 0) {
        return false;
      }
      // if (count(begin(s), end(s), '0') == (int)s.size()) {
      //   return false;
      // }
      bool ex = false;
      for (char c : s) {
        if (zero > 1 and c == '0') ex = true;
        if (c == '2') ex = true;
        if (c == '4') ex = true;
        if (c == '6') ex = true;
        if (c == '8') ex = true;
      }
      if (not ex) return false;
      int sum = 0;
      for (char c : s) {
        sum += c - '0';
      }
      if (sum % 3) {
        return false;
      }
      return true;
    }();
    cout << (ok ? "red" : "cyan") << '\n';
  }
}