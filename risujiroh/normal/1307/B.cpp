#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int mx = 0;
    for (auto&& e : a) {
      cin >> e;
      mx = max(mx, e);
    }
    if (find(begin(a), end(a), x) != end(a)) {
      cout << "1\n";
    } else {
      cout << max((x + mx - 1) / mx, 2) << '\n';
    }
  }
}