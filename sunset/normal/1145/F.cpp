#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string t = "AEFHIKLMNTVWXYZ";
  string s;
  cin >> s;
  bool foo = true, bar = true; 
  for (auto c : s) {
    bool found = false;
    for (auto d : t) {
      if (d == c) {
        found = true;
      }
    }
    if (found) {
      foo = false;
    } else {
      bar = false;
    }
  }
  cout << (foo || bar ? "YES" : "NO") << "\n";
  return 0;
}