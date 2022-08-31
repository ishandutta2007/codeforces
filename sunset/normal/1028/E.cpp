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
    scanf("%d", &a[i]);
  }
  if (!*max_element(a.begin(), a.end())) {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      printf("%d%c", 1, i == n - 1 ? '\n' : ' ');
    }
    return 0;
  }
  if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
    puts("NO");
    return 0;
  }
  puts("YES");
  vector<long long> answer(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] < a[(i + 1) % n]) {
      answer[(i + 1) % n] = a[(i + 1) % n];
      for (int j = 0; j < n - 1; ++j) {
        int p = (i - j + n) % n;
        answer[p] = answer[(p + 1) % n] + a[p];
        if (answer[p] < (1 << 30)) {
          answer[p] += answer[(p + 1) % n] * (1 << 30);
        }
      }
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", answer[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}