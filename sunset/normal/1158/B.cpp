#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  while ((int) s.size() < n) {
    for (int i = 0; i < (n - k) / 2; ++i) {
      s += "0";
    }
    s += "1";
  }
  cout << s.substr(0, n) << "\n";
  return 0;
}