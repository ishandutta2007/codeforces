#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  int xor_a = 0;
  for (auto&& e : a) {
    cin >> e;
    xor_a ^= e;
  }
  int res = 0;
  for (int k = 0; k < 25; ++k) {
    int cur = xor_a >> k & 1;
    cur *= n - 1;
    cur &= 1;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      b[i] = a[i] & ~(-1u << k);
    }
    sort(begin(b), end(b));
    long long cnt = 0;
    int r = 0;
    for (int i = n; i--; ) {
      while (r < n and b[i] + b[r] < 1 << k) {
        ++r;
      }
      cnt += n - r;
    }
    for (int e : b) {
      cnt -= 2 * e >= 1 << k;
    }
    cnt /= 2;
    cur ^= cnt & 1;
    res |= cur << k;
  }
  cout << res << '\n';
}