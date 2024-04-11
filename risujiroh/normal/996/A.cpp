#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a = {1, 5, 10, 20, 100};
  sort(a.rbegin(), a.rend());
  int res = 0;
  for (int i = 0; i < 5; i++) {
    res += n / a[i];
    n %= a[i];
  }
  cout << res << '\n';
  return 0;
}