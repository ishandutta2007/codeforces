#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    int res = a[0];
    for (int i = 1; i < n; ++i) {
      while (d >= i and a[i]) {
        --a[i];
        d -= i;
        ++res;
      }
    }
    cout << res << '\n';
  }
}