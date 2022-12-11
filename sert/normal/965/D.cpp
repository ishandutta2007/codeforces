#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n - 1);
  for (int &x : a) cin >> x;
  int sum = 0, mn = (int)1e9 + 41;
  for (int i = 0; i < n - 1; i++) {
    sum += a[i];
    if (i >= k) sum -= a[i - k];
    if (i >= k - 1) mn = min(mn, sum);
  }
  cout << mn << "\n";
  return 0;
}