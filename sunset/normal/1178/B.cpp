#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  long long a = 1;
  long long b = 0;
  long long c = 0;
  long long d = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    if (s[i] == 'o') {
      c += b;
      ++j;
    } else {
      while (j < n && s[j] == 'v') {
        ++j;
      }
      b += a * (j - i - 1);
      d += c * (j - i - 1);
    }
  }
  cout << d << "\n";
  return 0;
}