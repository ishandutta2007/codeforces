#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 1; i < 1e5; ++i) {
      res.push_back(n / i);
    }
    int x = res.back();
    while (x--) {
      res.push_back(x);
    }
    sort(begin(res), end(res));
    res.erase(unique(begin(res), end(res)), end(res));
    int m = res.size();
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " \n"[i == m - 1];
    }
  }
}