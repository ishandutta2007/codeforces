#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int s = accumulate(a.begin(), a.end(), 0);
  int res = 0, i = 0;
  while (2 * s < 9 * n) {
    s += 5 - a[i];
    i++;
    res++;
  }
  cout << res << '\n';
  return 0;
}