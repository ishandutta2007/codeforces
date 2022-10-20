#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t(n, '?');
    int m = n / 2 - k + 1;
    fill(begin(t), begin(t) + m, '(');
    fill(begin(t) + m, begin(t) + 2 * m, ')');
    for (int i = 2 * m; i < n; i += 2) {
      t[i] = '(';
      t[i + 1] = ')';
    }
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
      int j = i + s.substr(i).find(t[i]);
      cout << i + 1 << ' ' << j + 1 << '\n';
      reverse(begin(s) + i, begin(s) + j + 1);
    }
  }
}