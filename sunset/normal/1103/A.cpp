#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int foo = 0, bar = 0;
  for (auto c : s) {
    if (c == '0') {
      cout << foo + 1 << " " << 1 << "\n";
      foo = (foo + 2) % 4;
    } else {
      cout << bar + 1 << " " << 2 << "\n";
      bar = (bar + 1) % 4;
    }
  }
  return 0;
}