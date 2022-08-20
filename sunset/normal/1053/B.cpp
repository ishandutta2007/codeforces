#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    a[i] = __builtin_popcountll(x);
  }
  long long answer = 0;
  vector<int> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
  }
  vector<int> zero(n + 1);
  for (int i = 0; i < n; ++i) {
    zero[i + 1] = zero[i] ^ (a[i] & 1);
  }
  vector<int> sum_zero(n + 2);
  for (int i = 0; i <= n; ++i) {
    sum_zero[i + 1] = sum_zero[i] + zero[i];
  }
  
  auto query = [&](int l, int r, int t) {
    long long result = 0;
    for (int i = l, j = l - 1, k = l; i <= r; ++i) {
      if (j < i) {
        for (j = i; j <= r && a[j] != t; ++j);
        if (j > r) {
          return result;
        }
      }
      for (k = max(k, j); k <= r && sum[k + 1] - sum[i] < (t << 1); ++k);
      if (k > r) {
        return result;
      }
      if (zero[i]) {
        result += sum_zero[r + 2] - sum_zero[k + 1];
      } else {
        result += r - k + 1;
        result -= sum_zero[r + 2] - sum_zero[k + 1];
      }
    }
    return result;
  };
  
  for (int t = 0; t < 60; ++t) {
    int last = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > t) {
        answer += query(last, i - 1, t);
        last = i + 1;
      }
    }
    answer += query(last, n - 1, t);
  }
  printf("%lld\n", answer);
  return 0;
}