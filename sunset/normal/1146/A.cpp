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
  cout << min(a * 2 - 1, (int) s.size()) << "\n";
  return 0;
}