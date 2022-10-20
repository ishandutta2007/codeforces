#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<int> res;
  auto add = [&](int x) {
    res.push_back(x);
    rotate(begin(s), end(s) - x, end(s));
    reverse(begin(s), begin(s) + x);
  };
  for (int k = 0; k < n; ++k) {
    if (k % 2 == 0) {
      auto i = s.find(t[k], k);
      if (i == string::npos) {
        cout << "-1\n";
        exit(0);
      }
      add(n - i);
      add(i + 1);
      add(n - i - 1);
    } else {
      auto i = s.find(t[k]);
      if (i >= n - k) {
        cout << "-1\n";
        exit(0);
      }
      add(n - i - 1);
      add(1);
    }
  }
  if (n % 2 == 0) {
    add(n);
  }
  assert(s == t);
  int m = res.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}