#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> value(n), mask(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> value[i] >> mask[i];
    sum += value[i];
  }
  if (sum < 0) {
    for (int i = 0; i < n; ++i) {
      value[i] *= -1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 63; ++i) {
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      if (mask[j] == 1ll << i) {
        sum += value[j];
      }
    }
    if (sum > 0) {
      ans |= 1ll << i;
      for (int j = 0; j < n; ++j) {
        if (mask[j] >> i & 1) {
          value[j] *= -1;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (mask[j] >> i & 1) {
        mask[j] ^= 1ll << i;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}