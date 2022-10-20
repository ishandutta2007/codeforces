#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t = s.substr(0, k);
  cout << n << '\n';
  for (int i = 0; i < n; i += k) {
    int len = min(k, n - i);
    if (s.substr(i, len) < t.substr(0, len)) {
      break;
    }
    if (s.substr(i, len) > t.substr(0, len)) {
      int j = k - 1;
      while (t[j] == '9') {
        --j;
      }
      ++t[j];
      while (++j < k) {
        t[j] = '0';
      }
      break;
    }
  }
  while ((int)t.size() < n) {
    t += t;
  }
  cout << t.substr(0, n) << '\n';
}