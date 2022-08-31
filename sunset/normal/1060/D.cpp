#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long answer = n;
  for (int i = 0; i < n; ++i) {
    answer += max(a[i], b[i]);
  }
  printf("%lld\n", answer);
  return 0;
}