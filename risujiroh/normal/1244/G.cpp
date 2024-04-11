#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    k -= i;
  }
  if (k < 0) {
    cout << "-1\n";
    return 0;
  }
  vector<int> p(n);
  set<long long> se;
  for (int i = 0; i < n; ++i) {
    se.insert(i);
  }
  for (int x = n - 1; x >= 0; --x) {
    int i = *se.lower_bound(x - k);
    p[i] = x;
    se.erase(i);
    k -= max(x - i, 0);
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += max(i, p[i]) + 1;
  }
  cout << res << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << i << " \n"[i == n];
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] + 1 << " \n"[i == n - 1];
  }
}