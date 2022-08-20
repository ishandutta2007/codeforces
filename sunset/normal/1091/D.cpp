#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (long long) x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> fact(n + 1), inv_fact(n + 1);
  fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
  for (int i = 2; i <= n; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mul(md - md / i, inv_fact[md % i]);
  }
  for (int i = 2; i <= n; ++i) {
    inv_fact[i] = mul(inv_fact[i - 1], inv_fact[i]);
  }
  auto binom = [&](int x, int y) {
    return mul(fact[x], mul(inv_fact[y], inv_fact[x - y]));
  };
  int answer = fact[n];
  for (int i = 1; i < n; ++i) {
    add(answer, mul(binom(n, i), mul(fact[i], fact[n - i] - 1)));
  }
  printf("%d\n", answer);
  return 0;
}