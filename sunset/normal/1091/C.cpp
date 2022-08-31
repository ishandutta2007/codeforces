#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<long long> answer;
  auto add = [&](int m) {
    answer.push_back((long long) (n + 2) * (m + 1) / 2 - (n + 1));
  };
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      add(i);
      if (i * i < n) {
        add(n / i);
      }
    }
  }
  sort(answer.begin(), answer.end());
  for (int i = 0; i < answer.size(); ++i) {
    printf("%lld%c", answer[i], i == answer.size() - 1 ? '\n' : ' ');
  }
  return 0;
}