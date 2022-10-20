#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  vector<string> s(2);
  cin >> s[0] >> s[1];
  int n = s[0].size();

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    vector<char> c(4);
    c[0] = s[0][i];
    c[1] = s[0][i + 1];
    c[2] = s[1][i];
    c[3] = s[1][i + 1];
    sort(c.begin(), c.end());
    if (c[3] == '0') {
      res++;
      s[0][i] = s[0][i + 1] = s[1][i] = 'X';
    } else if (c[2] == '0') {
      res++;
      s[0][i] = s[0][i + 1] = s[1][i] = s[1][i + 1] = 'X';
    }
  }
  cout << res << '\n';
  return 0;
}