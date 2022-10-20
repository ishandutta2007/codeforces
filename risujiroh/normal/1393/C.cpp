#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int _ = n; _--; ) {
      int a;
      cin >> a;
      --a;
      ++c[a];
    }
    int mx = *max_element(begin(c), end(c));
    int cnt = count(begin(c), end(c), mx);
    cout << (n - mx - (cnt - 1)) / (mx - 1) << '\n';
  }
}