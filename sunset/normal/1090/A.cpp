#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> high(n);
  vector<int> size(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &size[i]);
    for (int j = 0; j < size[i]; ++j) {
      int x;
      scanf("%d", &x);
      high[i] = max(high[i], x);
    }
  }
  int result = *max_element(high.begin(), high.end());
  long long answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += (long long)size[i] * (result - high[i]);
  }
  printf("%lld\n", answer);
  return 0;
}