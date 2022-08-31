#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  string foo, bar;
  cin >> foo;
  for (int i = 0; i < 5; ++i) {
    cin >> bar;
    if (foo[0] == bar[0] || foo[1] == bar[1]) {
      cout << "YES" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
  return 0;
}