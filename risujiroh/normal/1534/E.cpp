#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  if (n & 1 and ~k & 1) {
    cout << -1 << endl;
    exit(0);
  }
  vector<int> c(n, 1);
  int sum = n;
  for (int i = 0;; ++i) {
    if ([&]() -> bool {
          if (sum % k) return false;
          return *max_element(begin(c), end(c)) <= sum / k;
        }())
      break;
    c[i % n] += 2;
    sum += 2;
  }
  int ans = 0;
  while (true) {
    vector<int> order(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return c[i] > c[j]; });
    if (c[order[0]] == 0) break;
    cout << '?';
    for (int z = 0; z < k; ++z) {
      cout << ' ' << order[z] + 1;
      --c[order[z]];
    }
    cout << endl;
    int t;
    cin >> t;
    ans ^= t;
  }
  cout << "! " << ans << endl;
}