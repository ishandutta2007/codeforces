#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  VI b(m); for (int i = 0; i < m; i++) cin >> b[i];
  sort(b.begin(), b.end());
  for (auto&& i : a) {
    if (binary_search(b.begin(), b.end(), i)) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  return 0;
}