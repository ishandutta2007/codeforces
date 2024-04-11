#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  for (auto&& e : l) {
    cin >> e;
  }
  if (accumulate(begin(l), end(l), 0LL) < n) {
    cout << "-1\n";
    exit(0);
  }
  for (int i = 0; i < m; ++i) {
    if (i + l[i] > n) {
      cout << "-1\n";
      exit(0);
    }
  }
  vector<int> res(m + 1);
  res[m] = n;
  for (int i = m; i--; ) {
    res[i] = max(res[i + 1] - l[i], i);
  }
  for (int i = 0; i < m; ++i) {
    cout << res[i] + 1 << " \n"[i == m - 1];
  }
}