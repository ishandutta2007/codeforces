#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, b; cin >> n >> b;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  
  int odd = 0;
  VI c;
  for (int i = 0; i < n - 1; i++) {
    odd += a[i] & 1;
    if (odd << 1 == i + 1) {
      c.push_back(abs(a[i + 1] - a[i]));
    }
  }

  sort(c.begin(), c.end());
  int res = 0;
  for (auto&& i : c) {
    b -= i;
    if (b < 0) break;
    res++;
  }
  cout << res << '\n';
  return 0;
}