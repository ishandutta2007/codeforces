#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];

  if (n == 1 or n == 2 and a[0] == a[1]) {
    cout << -1 << '\n';
  } else {
    cout << 1 << '\n';
    int s = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n; i++) {
      if (a[i] << 1 != s) {
        cout << i + 1 << '\n';
        return 0;
      }
    }
  }
  return 0;
}