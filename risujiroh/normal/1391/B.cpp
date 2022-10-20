#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto&& e : s) cin >> e;
    int res = count(begin(s.back()), end(s.back()), 'D');
    for (int i = 0; i < n; ++i) {
      res += s[i].back() == 'R';
    }
    cout << res << '\n';
  }
}