#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  bitset<200000> bs;
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    bs[i] = c - '0';
  }
  int s = bs.count();
  V<bool> a(n);
  for (int k = 1; k < n; ++k) {
    if (n % k) continue;
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      int t = 0;
      for (int j = i; j < n; j += k) t += bs[j];
      if (t & 1) {
        ok = false;
        break;
      }
    }
    a[k] = ok;
  }
  int res = !s;
  for (int k = 1; k < n; ++k) {
    int d = __gcd(n, k);
    res += a[d];
  }
  cout << res << '\n';
}