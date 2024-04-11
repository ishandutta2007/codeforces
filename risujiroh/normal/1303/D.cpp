#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    int m;
    cin >> m;
    vector<long long> c(30);
    long long sum = 0;
    while (m--) {
      int a;
      cin >> a;
      ++c[__lg(a)];
      sum += a;
    }
    if (n > sum) {
      cout << "-1\n";
      continue;
    }
    long long res = 0;
    for (int i = 30; i--; ) {
      long long x = min(n >> i, c[i]);
      n -= x << i;
      c[i] -= x;
      sum -= x << i;
      if (sum - (c[i] << i) < n) {
        long long y = (n - (sum - (c[i] << i)) + (1 << i) - 1) / (1 << i);
        assert(y <= c[i]);
        c[i] -= y;
        res += y;
        c[i - 1] += 2 * y;
      }
      sum -= c[i] << i;
    }
    cout << res << '\n';
  }
}