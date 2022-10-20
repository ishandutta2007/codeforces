#include <bits/stdc++.h>
using namespace std;

constexpr int th = 128;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  long long res = 0;
  {
    int lim = (th - 1) * n;
    vector<int> a(n), c(2 * lim + 1);
    for (int r = 0; r < min(th, n); ++r) {
      for (int i = 0; i < n; ++i) {
        a[i] = s[i] == '1' ? r : -1;
      }
      fill(begin(c) + (lim - r * n), begin(c) + (lim + r * n + 1), 0);
      int sum = lim;
      ++c[sum];
      for (int i = 0; i < n; ++i) {
        sum += a[i];
        res += c[sum]++;
      }
    }
  }
  {
    vector<int> c(n + 1);
    for (int i = n; i--; ) {
      c[i] = (s[i] == '1') + c[i + 1];
    }
    vector<int> z(n + 1);
    for (int i = n; i--; ) {
      if (s[i] == '0') {
        z[i] = 1 + z[i + 1];
      }
    }
    for (int m = 1; m * (1 + th) <= n; ++m) {
      int r = 0;
      for (int l = 0; l < n; ++l) {
        while (r < n and c[l] - c[r] < m) {
          ++r;
        }
        if (c[l] - c[r] != m) {
          continue;
        }
        int lb = max(r - l, (1 + th) * m), ub = r - l + z[r];
        if (lb > ub) {
          continue;
        }
        res += ub / m - (lb + m - 1) / m + 1;
      }
    }
  }
  cout << res << '\n';
}