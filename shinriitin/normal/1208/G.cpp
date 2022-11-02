#include <bits/stdc++.h>

const int max_N = (int)4e6 + 21;

int n, k, phi[max_N];

std::vector<int> prime;

void init() {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!phi[i]) {
      prime.push_back(i);
      phi[i] = i - 1;
    }
    for (auto& p : prime) {
      if (1LL * i * p > n)
        break;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      } else {
        phi[i * p] = phi[i] * (p - 1);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  init();
  std::nth_element(phi + 3, phi + 2 + k, phi + n + 1);
  long long ans = 1 + (k > 1);
  for (int i = 0; i < k; ++i) {
    ans += phi[i + 3];
  }
  printf("%lld\n", ans);
}