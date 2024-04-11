#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, value;
  scanf("%d %d", &n, &value);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  long long answer = 0;
  for (int i = 0; i < n >> 1; ++i) {
    if (a[i] > value) {
      answer += a[i] - value;
    }
  }
  answer += abs(a[n >> 1] - value);
  for (int i = n - 1; i > n >> 1; --i) {
    if (a[i] < value) {
      answer += value - a[i];
    }
  }
  printf("%lld\n", answer);
  return 0;
}