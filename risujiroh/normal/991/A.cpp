#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int a, b, c, n; cin >> a >> b >> c >> n;
  int d = n - (a + b - c);
  if (1 <= d and d <= n and a <= n and b <= n and c <= n and a - c >= 0 and b - c >= 0) {
    cout << d << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}